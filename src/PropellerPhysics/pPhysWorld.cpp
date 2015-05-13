#include <PropellerPhysics/precompiled.h>
#include <PropellerPhysics/pPhysWorld.h>
#include <PropellerPhysics/pPhysDebugDrawInterface.h>
#include <PropellerPhysics/pPhysCollisionChecker.h>
#include <PropellerPhysics/pPhysCollisionResolver.h>

#include <PropellerPhysics/pPhysCircleShape.h>

#include <sstream>

namespace pPhys
{

	World::World(Vec2 gravity)
		: gravity(gravity/10)
		, debugDraw(NULL)
		, substepCount(5)
	{ }

	void World::addObject(Object *obj)
	{
		if (obj->shape == NULL)
		{
			debugDraw->logWarning("Object doesn't have a shape! Ignoring addObject()");
			return;
		}

		objects.push_back(obj);
	}

	void World::removeObject(Object *obj)
	{
		//TODO: remove queue could improve the performance (?)
		for (unsigned i = 0; i < objects.size(); ++i)
		{
			if (objects[i] == obj)
			{
				objects.erase(objects.begin() + i);

				return;
			}
		}
	}

	void World::step(float delta)
	{
		// Step is done in following steps
		// 1) Apply impulses/velocities
		// 2) Check for collisions
		// 2) Resolve collisions
		// 3) debug draw, if enabled

		// Calculate velocities
		for (unsigned i = 0; i < objects.size(); ++i)
		{
			if (objects[i]->isKinematic())
				continue; // velocities are not calculated for kinematic objects

			if (objects[i]->sleep)
				continue;

			Vec2 acceleration = gravity;

			//TODO: handle impulse to acceleration

			objects[i]->velocity += acceleration;

			objects[i]->position += objects[i]->velocity;

			objects[i]->stepTime = delta;
		}

		// Check for collisions (before moving the objects)
		for (unsigned i = 0; i < objects.size(); ++i)
		{
			if (objects[i]->sleep)
				continue; // don't process sleeppers until they are collided upon

			//TODO: QuadTree or similar optimization would help here

			for (unsigned a = 0; a < objects.size(); ++a)
			{
				if (objects[a]->isKinematic())
					continue; // collision is handled the other way

				if (objects[i] == objects[a])
					continue;

				//SubStep to check for a possible collision
				float step = delta / substepCount;

				bool hit;
				Vec2 startPosObjectI = objects[i]->getPosition();
				Vec2 startPosObjectA = objects[a]->getPosition();

				for (float t = 0; t < delta; t += step) //step < delta ok ?
				{
					// move the objects 
					pPhys::Vec2 preColPos_i = objects[i]->getPosition();
					pPhys::Vec2 preColPos_a = objects[a]->getPosition();

					objects[i]->setPosition(objects[i]->getPosition() + objects[i]->getVelocity() / substepCount);
					objects[a]->setPosition(objects[a]->getPosition() + objects[a]->getVelocity() / substepCount);

					// check for collision during this substep
					hit = CollisionChecker::checkCollision(objects[i], objects[a]);

					if (hit == true)
					{
						debugDraw->logDebug(std::string("hit!"));
						CollisionResolver::resolveCollisions(objects[i], objects[a]);
						// Calculate time for movement after the step

						objects[i]->stepTime = delta - t; // how many percentages we managed to move before the hit
						objects[a]->stepTime = delta - t; // how many percentages we managed to move before the hit

						// move to substepped position before collision, steptime should have time moved with substepping
						objects[i]->setPosition(preColPos_i);
						objects[a]->setPosition(preColPos_a);

						break;
					}
				}
				if (hit == false)
				{
					// return objects to the positions, if hit happened, the objects are left where the substep detected the collision
					objects[i]->setPosition(startPosObjectI);
					objects[a]->setPosition(startPosObjectA);
				}
			}
		}


		// Apply velocities
		for (unsigned i = 0; i < objects.size(); ++i)
		{
			if (objects[i]->isKinematic())
				continue; // velocities are not calculated for kinematic objects

			if (objects[i]->sleep)
				continue;

			float sleepTreshold = 0.100f;
			if (objects[i]->velocity.x < sleepTreshold && objects[i]->velocity.x > -sleepTreshold && objects[i]->velocity.y < sleepTreshold && objects[i]->velocity.y > -sleepTreshold)
			{
				objects[i]->sleep = true;
				objects[i]->velocity.x = 0;
				objects[i]->velocity.y = 0;
			}

			pPhys::Vec2 dMov = objects[i]->velocity * objects[i]->stepTime;
			objects[i]->position += dMov * objects[i]->stepTime;
		}
	}

	void World::drawWorld()
	{
		if (debugDraw == NULL)
			return;

		for (unsigned i = 0; i < objects.size(); ++i)
		{
			if (objects[i]->isKinematic())
				continue;

			debugDraw->positionEcho(objects[i]);

			CircleShape *shape = dynamic_cast<CircleShape*>(objects[i]->getShape());

			if (shape != NULL)
				debugDraw->drawCircle(objects[i]->getPosition(), shape->getRadius());
		}

		debugDraw->flip();
	}

	void World::clearAllDynamicObjects()
	{
		for (unsigned i = 0; i < objects.size(); ++i)
		{
			if (objects[i]->isKinematic())
				continue;

			objects.erase(objects.begin() + i);

			--i;
		}
	}

}

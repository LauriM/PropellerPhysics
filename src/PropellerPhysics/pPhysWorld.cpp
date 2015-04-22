#include <PropellerPhysics/precompiled.h>
#include <PropellerPhysics/pPhysWorld.h>
#include <PropellerPhysics/pPhysDebugDrawInterface.h>
#include <PropellerPhysics/pPhysCollisionChecker.h>

namespace pPhys
{

	World::World(Vec2 gravity)
		: gravity(gravity)
		, debugDraw(NULL)
		, substepCount(25)
	{ }

	void World::addObject(Object *obj)
	{
		if (obj->shape == nullptr)
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

			Vec2 acceleration = gravity;

			//TODO: handle impulse to acceleration

			objects[i]->velocity += acceleration;

			objects[i]->position += objects[i]->velocity;
		}

		// Check for collisions (before moving the objects)
		for (unsigned i = 0; i < objects.size(); ++i)
		{
			//TODO: QuadTree or similar optimization would help here

			for (unsigned a = 0; a < objects.size(); ++a)
			{
				if (objects[i]->isKinematic())
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
					objects[i]->setPosition(objects[i]->getPosition() + objects[i]->getVelocity() / substepCount);
					objects[a]->setPosition(objects[a]->getPosition() + objects[a]->getVelocity() / substepCount);

					// check for collision during this substep
					hit = CollisionChecker::checkCollision(objects[i], objects[a]);

					if (hit == true)
					{
						debugDraw->logDebug(std::string("hit!"));
					}
				}

				// return objects to the positions
				objects[i]->setPosition(startPosObjectI);
				objects[a]->setPosition(startPosObjectA);
			}
		}

		// Apply velocities
		for (unsigned i = 0; i < objects.size(); ++i)
		{
			if (objects[i]->isKinematic())
				continue; // velocities are not calculated for kinematic objects

			objects[i]->position += objects[i]->velocity;
		}
	}

	void World::drawWorld()
	{
		if (debugDraw == NULL)
			return;

		for (unsigned i = 0; i < objects.size(); ++i)
		{
			debugDraw->positionEcho(objects[i]->getPosition());
		}
	}

}

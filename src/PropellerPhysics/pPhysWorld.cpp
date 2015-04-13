#include <PropellerPhysics/precompiled.h>
#include <PropellerPhysics/pPhysWorld.h>
#include <PropellerPhysics/pPhysDebugDrawInterface.h>

namespace pPhys
{

	World::World(Vec2 gravity)
		: gravity(gravity)
		, debugDraw(NULL)
	{ }

	void World::addObject(Object *obj)
	{
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

		for (unsigned i = 0; i < objects.size(); ++i)
		{
			Vec2 acceleration = gravity;

			//TODO: handle impulse to acceleration

			objects[i]->velocity += acceleration;

			if (!objects[i]->kinematic)
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

#include <PropellerPhysics/pPhysWorld.h>
#include <PropellerPhysics/pPhysDebugDrawInterface.h>

namespace pPhys
{

	World::World(Vec2 gravity)
		: gravity(gravity)
		, debugDraw(NULL)
	{ }


	void World::step(float delta)
	{
		// Step is done in following steps
		// 1) Apply impulses/velocities
		// 2) Resolve collisions
		// 3) debug draw, if enabled

	}


	void World::drawWorld()
	{
		if (debugDraw == NULL)
			return;

		debugDraw->positionEcho(Vec2(666, 12));
	}
}

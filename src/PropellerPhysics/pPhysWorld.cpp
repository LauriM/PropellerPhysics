#include <PropellerPhysics\pPhysWorld.h>

namespace pPhys
{

	World::World(Vec2 gravity)
		: gravity(gravity)
	{ }


	void World::step(float delta)
	{
		// Step is done in following steps
		// 1) Apply impulses/velocities
		// 2) Resolve collisions
	}

}

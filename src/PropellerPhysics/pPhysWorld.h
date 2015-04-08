#ifndef PPHYSWORLD_H
#define PPHYSWORLD_H

#include <PropellerPhysics/pPhysVector.h>

#include <vector>

namespace pPhys {

	class World
	{
	private:
		Vec2 gravity;

	public:
		World(Vec2 gravity);
	};

}

#endif
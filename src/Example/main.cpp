#include <iostream>

#include <PropellerPhysics/PropellerPhysics.h>

#include <PropellerPhysics/pPhysWorld.h>

#include "TextDebugDraw.h"

int main()
{
	std::cout << "hello hahahaha\n";

	pPhys::World *world = new pPhys::World(pPhys::Vec2(0.0, -9.81));

	world->setDebugDrawInterface(new TextDebugDraw());

	world->drawWorld();

	return 0;
}
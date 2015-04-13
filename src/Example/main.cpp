#include <iostream>

#include <PropellerPhysics/PropellerPhysics.h>

#include <PropellerPhysics/pPhysWorld.h>

#include "TextDebugDraw.h"

int main()
{
	std::cout << "hello hahahaha\n";

	pPhys::World *world = new pPhys::World(pPhys::Vec2(0.0, -9.81));

	world->setDebugDrawInterface(new TextDebugDraw());

	pPhys::Object *ball = new pPhys::Object();

	ball->setPosition(pPhys::Vec2(0.f, 100.f));

	world->addObject(ball);

	for (unsigned i = 0; i < 60; ++i)
	{
		world->step(0.1);
		world->drawWorld();
	}

#ifdef _WIN32
	std::cin.get();
#endif

	return 0;
}
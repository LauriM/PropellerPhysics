#include <iostream>

#include <PropellerPhysics/PropellerPhysics.h>

#include <PropellerPhysics/pPhysWorld.h>

#include "TextDebugDraw.h"

int main()
{
	std::cout << "hello hahahaha\n";

	pPhys::World *world = new pPhys::World(pPhys::Vec2(0.0, -9.81));

	world->setDebugDrawInterface(new TextDebugDraw());

	{
		pPhys::Object *ball = new pPhys::Object();

		ball->setShape(new pPhys::CircleShape(1));

		ball->setPosition(pPhys::Vec2(0.f, 100.f));

		world->addObject(ball);
	}

	{
		pPhys::Object *ball = new pPhys::Object();

		ball->setShape(new pPhys::CircleShape(1));
		ball->setKinematic(true);
		ball->setPosition(pPhys::Vec2(0.f, 50.f));

		world->addObject(ball);
	}

	for (unsigned i = 0; i < 60; ++i)
	{
		world->step(0.1);
		world->drawWorld();
	}

	return 0;
}
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
		ball->setVelocity(pPhys::Vec2(0.f, 15.f));
		ball->setKinematic(false);
		ball->setMass(1.f);

		world->addObject(ball);
	}

	{
		pPhys::Object *ball = new pPhys::Object();

		ball->setShape(new pPhys::CircleShape(1));
		ball->setKinematic(true);
		ball->setPosition(pPhys::Vec2(0.f, 48.f));
		ball->setMass(2.f);

		world->addObject(ball);
	}

	{
		pPhys::Object *ground = new pPhys::Object();

		// horizontal line at origo
		ground->setShape(new pPhys::LineShape(0));
		ground->setKinematic(true);
		ground->setPosition(pPhys::Vec2(0.f, 1.f));

		world->addObject(ground);
	}

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
#include <iostream>

#include <PropellerPhysics/PropellerPhysics.h>

#include <PropellerPhysics/pPhysWorld.h>

#include "TextDebugDraw.h"
#include "SFMLDebugDraw.h"

int main()
{
	std::cout << "hello hahahaha\n";

	pPhys::World *world = new pPhys::World(pPhys::Vec2(0.0, -2.81));

	world->setDebugDrawInterface(new SFMLDebugDraw());

	{
		pPhys::Object *ball = new pPhys::Object();

		ball->setShape(new pPhys::CircleShape(10)); //TODO: ball size not handled

		ball->setPosition(pPhys::Vec2(0.f, 50.f));
		ball->setVelocity(pPhys::Vec2(20.f, 20.f));
		ball->setKinematic(false);
		ball->setMass(1.f);

		world->addObject(ball);
	}

	{
		pPhys::Object *ball = new pPhys::Object();

		ball->setShape(new pPhys::CircleShape(25)); //TODO: ball size not handled

		ball->setPosition(pPhys::Vec2(0.f, 50.f));
		ball->setVelocity(pPhys::Vec2(-20.f, 20.f));
		ball->setKinematic(false);
		ball->setMass(1.f);

		world->addObject(ball);
	}

	/*
	{
		pPhys::Object *ball = new pPhys::Object();

		ball->setShape(new pPhys::CircleShape(1));
		ball->setKinematic(true);
		ball->setPosition(pPhys::Vec2(0.f, 48.f));
		ball->setMass(2.f);

		world->addObject(ball);
	}
	*/

	{//bottom
		pPhys::Object *ground = new pPhys::Object();

		// With line, the position doesn't matter, its all in the lineshape object
		ground->setShape(new pPhys::LineShape(pPhys::Vec2(0.11f, 1), 200)); // horizontal line at origo
		ground->setKinematic(true);

		world->addObject(ground);
	}

	{//left
		pPhys::Object *ground = new pPhys::Object();

		// With line, the position doesn't matter, its all in the lineshape object
		ground->setShape(new pPhys::LineShape(pPhys::Vec2(1, 0.1), 200)); 
		ground->setKinematic(true);

		world->addObject(ground);
	}

	{//right
		pPhys::Object *ground = new pPhys::Object();

		// With line, the position doesn't matter, its all in the lineshape object
		ground->setShape(new pPhys::LineShape(pPhys::Vec2(-1, 0.1), 200)); 
		ground->setKinematic(true);

		world->addObject(ground);
	}

	for (;;)
	{
		world->step(1.f / 60.f);
		world->drawWorld();
		//sf::sleep(sf::Time(sf::seconds(1 / 260.f)));
		sf::sleep(sf::Time(sf::seconds(1.f / 60.f)));
	}

#ifdef _WIN32
	std::cin.get();
#endif

	return 0;
}
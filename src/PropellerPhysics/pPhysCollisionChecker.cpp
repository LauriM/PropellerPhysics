#include <PropellerPhysics/precompiled.h>
#include <PropellerPhysics/pPhysObject.h>
#include <PropellerPhysics/pPhysShape.h>
#include <PropellerPhysics/pPhysCircleShape.h>
#include <PropellerPhysics/pPhysLineShape.h>
#include <PropellerPhysics/pPhysCollisionChecker.h>

namespace pPhys {

	bool CollisionChecker::checkCollision(Object *a, Object *b)
	{
		CircleShape *circleA = dynamic_cast<CircleShape*>(a->getShape());
		CircleShape *circleB = dynamic_cast<CircleShape*>(b->getShape());

		if (circleA != NULL && circleB != NULL)
		{
			// circle to circle!
			return circleToCircle(circleA, circleB);
		}

		return false;
	}

	bool CollisionChecker::circleToLine(CircleShape *a, LineShape *b)
	{
		return false; //TODO: not implemented!
	}

	bool CollisionChecker::circleToCircle(CircleShape *a, CircleShape *b)
	{
		Vec2 len = b->getParent()->getPosition();
		len -= a->getParent()->getPosition();

		float lenght = len.getLenght();

		//std::cout << "dist: " << lenght << "\n";

		return (lenght - b->getRadius() - a->getRadius()) < 0;
	}

}

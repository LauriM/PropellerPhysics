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

		{
			CircleShape *circleA = dynamic_cast<CircleShape*>(a->getShape());
			LineShape *lineB = dynamic_cast<LineShape*>(b->getShape());

			if (circleA != NULL && circleB != NULL)
			{
				// circle to circle!
				return circleToLine(circleA, lineB);
			}
		}
		
		{
			CircleShape *circleA = dynamic_cast<CircleShape*>(b->getShape());
			LineShape *lineB = dynamic_cast<LineShape*>(a->getShape());

			if (circleA != NULL && circleB != NULL)
			{
				// circle to circle!
				return circleToLine(circleA, lineB);
			}
		}

		return false;
	}

	bool CollisionChecker::circleToLine(CircleShape *circleShape, LineShape *lineShape)
	{
		// distance = P[i].x*Planes[j].a + P[i].y*Planes[j].b + Planes[j].c;

		Object *circle = circleShape->getParent();
		Object *line = lineShape->getParent();

		float distance = circle->getPosition().x * line->getPosition().x + circle->getPosition().y * lineShape->getNormal();

		std::cout << "dist: " << distance << "\n";

		return distance < 0; //TODO: not implemented!
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

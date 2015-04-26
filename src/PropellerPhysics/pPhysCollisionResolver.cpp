#include <PropellerPhysics/precompiled.h>
#include <PropellerPhysics/pPhysCollisionResolver.h>
#include <PropellerPhysics/pPhysCircleShape.h>
#include <PropellerPhysics/pPhysLineShape.h>
#include <PropellerPhysics/pPhysObject.h>

namespace pPhys {

	void CollisionResolver::resolveCollisions(Object *a, Object *b)
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
	}
	
	void CollisionResolver::circleToLine(CircleShape *circleShape, LineShape *lineShape)
	{
		Object *circle = circleShape->getParent();
		Object *line = lineShape->getParent();

		Vec2 circleVel = circle->getVelocity();

		Vec2 temp = lineShape->normal * lineShape->normal.getDotProduct(circleVel);

		circle->setVelocity(-(temp));
	}

	void CollisionResolver::circleToCircle(CircleShape *a, CircleShape *b) { } //not implemented

}
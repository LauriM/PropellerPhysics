#include <PropellerPhysics/precompiled.h>
#include <PropellerPhysics/pPhysCollisionResolver.h>
#include <PropellerPhysics/pPhysCircleShape.h>
#include <PropellerPhysics/pPhysLineShape.h>
#include <PropellerPhysics/pPhysObject.h>
#include <PropellerPhysics/pPhysVector.h>

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

		//2 * N*N•V[i];
		Vec2 temp = lineShape->normal * lineShape->normal.getDotProduct(circleVel);

		// TODO: the "non affected" x/y axis is resetted.
		circle->setVelocity(-(temp)  * 0.8f);
	}

	void CollisionResolver::circleToCircle(CircleShape *a, CircleShape *b) { } //not implemented

}
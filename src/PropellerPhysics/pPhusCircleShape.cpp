#include <PropellerPhysics/precompiled.h>
#include <PropellerPhysics/pPhysCircleShape.h>

namespace pPhys {

	CircleShape::CircleShape(float radius)
		: radius(radius)
	{ }

	bool CircleShape::checkCollision(Shape *other)
	{
		CircleShape *circleShape = dynamic_cast<CircleShape*>(other);

		if (circleShape != nullptr)
		{
			return circleCollision(circleShape);
		}

		// error: missing checks for collisions
		return false;
	}

	bool CircleShape::circleCollision(const CircleShape *other)
	{
		return false;
	}

}

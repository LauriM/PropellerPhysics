#include <PropellerPhysics/precompiled.h>
#include <PropellerPhysics/pPhysCircleShape.h>
#include <PropellerPhysics/pPhysObject.h>

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

	bool CircleShape::circleCollision(CircleShape *other)
	{
		Vec2 len = other->getParent()->getPosition();
		len -= getParent()->getPosition();

		float lenght = len.getLenght();

		std::cout << "dist: " << lenght << "\n";

		return (lenght - other->getRadius() - radius) < 0;
	}

}

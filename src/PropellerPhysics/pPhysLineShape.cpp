#include <PropellerPhysics/precompiled.h>
#include <PropellerPhysics/pPhysLineShape.h>

namespace pPhys {

	bool LineShape::checkCollision(Shape *other)
	{
		// Line is static, it doesn't move, doesn't cause collisions.
		// Other objects can collied into line
		return false;
	}

}
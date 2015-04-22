#include <PropellerPhysics/precompiled.h>
#include <PropellerPhysics/pPhysObject.h>
#include <PropellerPhysics/pPhysShape.h>

namespace pPhys {

	bool Object::resolveCollision(Object *other)
	{
		//TODO: increment the velocities temporary

		return shape->checkCollision(other->shape);

		//TODO: if collision ^^ -> setup new velocities and positions
	}

}
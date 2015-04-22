#include <PropellerPhysics/precompiled.h>
#include <PropellerPhysics/pPhysObject.h>
#include <PropellerPhysics/pPhysShape.h>

namespace pPhys {

	bool Object::checkCollision(Object *other)
	{
		return shape->checkCollision(other->shape);
	}

	void Object::resolveCollision(Object *other)
	{

	}

}
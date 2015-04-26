#ifndef PPHYSLINESHAPE_H
#define PPHYSLINESHAPE_H

#include <PropellerPhysics/pPhysShape.h>
#include <PropellerPhysics/pPhysVector.h>

namespace pPhys {

	class LineShape : public Shape
	{
	public:
		Vec2 normal;
		float distance;

	public:
		LineShape(Vec2 normal, float distance)
			: normal(normal)
			, distance(distance)
		{ }
	};

}

#endif

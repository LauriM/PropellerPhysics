#ifndef PPHYSLINESHAPE_H
#define PPHYSLINESHAPE_H

#include <PropellerPhysics/pPhysShape.h>
#include <PropellerPhysics/pPhysVector.h>

namespace pPhys {

	class LineShape : public Shape
	{
	private:
		float normal;

	public:
		LineShape(float normal)
			: normal(normal)
		{ }

		float getNormal() { return normal; }
	};

}

#endif

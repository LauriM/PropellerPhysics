#ifndef PPHYSCIRCLSHAPE_H
#define PPHYSCIRCLSHAPE_H

#include <PropellerPhysics/pPhysShape.h>

namespace pPhys {

	class CircleShape : public Shape
	{
	private:
		float radius;

	public:
		CircleShape(float radius)
			: radius(radius)
		{ }

		float getRadius() { return radius; }
	};

}

#endif

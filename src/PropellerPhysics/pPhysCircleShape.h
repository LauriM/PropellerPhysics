#ifndef PPHYSCIRCLSHAPE_H
#define PPHYSCIRCLSHAPE_H

#include <PropellerPhysics/pPhysShape.h>

namespace pPhys {

	class CircleShape : public Shape
	{
	private:
		float radius;

	private:
		bool circleCollision(const CircleShape *other);

	public:
		CircleShape(float radius);

		bool checkCollision(Shape *other);
	};

}

#endif
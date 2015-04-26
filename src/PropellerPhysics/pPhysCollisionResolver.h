#ifndef PPHYSCOLLISIONRESOLVER_H
#define PPHYSCOLLISIONRESOLVER_H

namespace pPhys {

	class Object;
	class CircleShape;
	class LineShape;

	class CollisionResolver
	{
	private:
		// Available shapes:
		//   * Line
		//   * Circle

		// Possible collisions:
		//   * Circle <-> Circle
		//   * Circle -> Line

		static void circleToLine(CircleShape *a, LineShape *b);
		static void circleToCircle(CircleShape *a, CircleShape *b);
	public:
		static void resolveCollisions(Object *a, Object *b);
	};


}

#endif
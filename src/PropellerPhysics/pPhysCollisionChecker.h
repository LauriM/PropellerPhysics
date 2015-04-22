#ifndef PPHYSCOLLISIONCHECKER_H
#define PPHYSCOLLISIONCHECKER_H

namespace pPhys {

	class Object;
	class CircleShape;
	class LineShape;

	/*
	 * Class containing collision checks between different shapes
	 */
	class CollisionChecker
	{
	private:
		// Avaivable shapes:
		//   * Line
		//   * Circle

		// Possible collisions:
		//   * Circle <-> Circle
		//   * Circle -> Line

		static bool circleToLine(CircleShape *a, LineShape *b);
		static bool circleToCircle(CircleShape *a, CircleShape *b);

	public:

		// Check if two objects are overlapping
		static bool checkCollision(Object *a, Object *b);
	};

}

#endif
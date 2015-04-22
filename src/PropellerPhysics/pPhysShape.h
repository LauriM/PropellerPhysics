#ifndef PPHYSSHAPE_H
#define PPHYSSHAPE_H

namespace pPhys {

	/**
	 * Represents the physical form of the object.
  	 */
	class Shape
	{
	private:

	public:
		virtual bool checkCollision(Shape *other) = 0;
	};

}

#endif
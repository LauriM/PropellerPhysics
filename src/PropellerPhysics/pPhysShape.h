#ifndef PPHYSSHAPE_H
#define PPHYSSHAPE_H

namespace pPhys {

	class Object;

	/**
	 * Represents the physical form of the object.
  	 */
	class Shape
	{
	private:
		Object *parent;

	public:
		virtual ~Shape() { }

		void setParent(Object *p) { parent = p; }
		Object *getParent() { return parent; }
	};

}

#endif
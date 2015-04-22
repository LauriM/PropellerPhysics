#ifndef PPHYSOBJECT_H
#define PPHYSOBJECT_H

#include <PropellerPhysics/pPhysVector.h>
#include <PropellerPhysics/pPhysShape.h>

namespace pPhys {

	class Object
	{
	private:
		Vec2 position;
		Vec2 velocity;
		bool kinematic;
		float mass;

		Shape *shape;

	public:
		Object()
			: position(Vec2(0, 0))
			, velocity(Vec2(0, 0))
			, kinematic(false)
			, shape(nullptr)
			, mass(0)
		{ }

		// Allows direct access
		friend class World;

		/* getters & setters */
		Vec2 &getPosition() { return position; }
		void setPosition(const Vec2 &pos) { position = pos; }

		Vec2 &getVelocity() { return velocity; }
		void setVelocity(const Vec2 &vel) { velocity = vel; }

		float getMass() { return mass; }
		void setMass(const float &m) { mass = m; }

		const bool &isKinematic() const { return kinematic; }
		void setKinematic(const bool &k) { kinematic = k; }

		void setShape(Shape *s) 
		{ 
			shape = s; 
			shape->setParent(this);
		}

		Shape *getShape() { return shape; }
	};

}

#endif
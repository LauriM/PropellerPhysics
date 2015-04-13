#ifndef PPHYSOBJECT_H
#define PPHYSOBJECT_H

#include <PropellerPhysics/pPhysVector.h>

namespace pPhys {

	class Object
	{
	private:
		Vec2 position;
		Vec2 velocity;
		bool kinematic;

	public:
		Object()
			: position(Vec2(0, 0))
			, velocity(Vec2(0, 0))
			, kinematic(false)
		{ }

		// Allows direct access
		friend class World;

		/* getters & setters */

		const Vec2 &getPosition() const { return position; }
		void setPosition(const Vec2 &pos) { position = pos; }

		const Vec2 &getVelocity() const { return velocity; }
		void setVelocity(const Vec2 &vel) { velocity = vel; }

		const bool &isKinematic() const { return kinematic; }
		void setKinematic(const bool k) { kinematic = k; }
	};

}

#endif
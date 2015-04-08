#ifndef PPHYSOBJECT_H
#define PPHYSOBJECT_H

#include <PropellerPhysics/pPhysVector.h>

namespace pPhys {

	class Object
	{
	private:
		Vec2 position;
		Vec2 velocity;

	public:
		Object()
			: position(Vec2(0, 0))
			, velocity(Vec2(0, 0))
		{ }

		// Allows direct access
		friend class World;

		/* getters & setters */

		const Vec2 &getPosition() const { return position; }
		void setPosition(const Vec2 &pos) { position = pos; }

		const Vec2 &getVelocity() const { return velocity; }
		void setVelocity(const Vec2 &vel) { velocity = vel; }
	};

}

#endif
#ifndef PPHYSWORLD_H
#define PPHYSWORLD_H

#include <PropellerPhysics/pPhysVector.h>

#include <vector>

namespace pPhys {

	class DebugDrawInterface;

	class World
	{
	private:
		Vec2 gravity;

		bool debugDrawEnabled;
		DebugDrawInterface *debugDraw;

	public:
		World(Vec2 gravity);

		void step(float delta);

		void drawWorld();

		void setDebugDrawInterface(DebugDrawInterface *debugDraw) { this->debugDraw = debugDraw; }

		/* getters & setters for data */
		bool isDebugDrawEnabled() const { return debugDrawEnabled; }
		void setDebugDrawEnabled(const bool d) { debugDrawEnabled = d; }
	};

}

#endif
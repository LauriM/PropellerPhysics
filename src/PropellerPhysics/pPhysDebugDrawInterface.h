#ifndef PPHYSDEBUGDRAWINTERFACE_H
#define PPHYSDEBUGDRAWINTERFACE_H

#include <PropellerPhysics/pPhysVector.h>

namespace pPhys {

	class DebugDrawInterface
	{
	public:
		// Print the position of the objects
		virtual void positionEcho(const Vec2 &pos) { };

		// Draw a line
		virtual void drawLine(const Vec2 &start, const Vec2 &end) = 0;

		virtual void drawBox(const Vec2 &pos, const Vec2 &size)
		{
			Vec2 lefttop = pos;
			Vec2 rightbottom = pos; rightbottom += size;

			Vec2 leftbottom = pos; leftbottom += Vec2(0, size.y);
			Vec2 righttop = pos; righttop += Vec2(size.x, 0);

			drawLine(lefttop, righttop);
			drawLine(righttop, rightbottom);
			drawLine(rightbottom, leftbottom);
			drawLine(leftbottom, lefttop);
		}
	};
}

#endif
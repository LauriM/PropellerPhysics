#pragma once

#include <PropellerPhysics/pPhysDebugDrawInterface.h>

class TextDebugDraw : public pPhys::DebugDrawInterface
{
public:
	void positionEcho(const pPhys::Vec2 &pos);
	void drawLine(const pPhys::Vec2 &start, const pPhys::Vec2 &end);
	void logWarning(const std::string msg);
};
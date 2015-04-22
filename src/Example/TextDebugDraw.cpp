#include <iostream>
#include <cmath>
#include "TextDebugDraw.h"


void TextDebugDraw::positionEcho(const pPhys::Vec2 &pos)
{
	std::cout << "Pos " << pos.x << " " << pos.y << "\n";
}

void TextDebugDraw::drawLine(const pPhys::Vec2 &start, const pPhys::Vec2 &end) { }

void TextDebugDraw::logWarning(const std::string msg)
{
	std::cout << "[WARNING] " << msg.c_str() << "\n";
}

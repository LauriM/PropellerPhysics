#include "TextDebugDraw.h"

#include <iostream>

void TextDebugDraw::positionEcho(const pPhys::Vec2 &pos)
{
	std::cout << "Pos " << pos.x << " " << pos.y << "\n";
}

void TextDebugDraw::drawLine(const pPhys::Vec2 &start, const pPhys::Vec2 &end) { }
#include <iostream>
#include <cmath>

#include <PropellerPhysics/pPhysObject.h>

#include "TextDebugDraw.h"


void TextDebugDraw::positionEcho(pPhys::Object *object)
{
	std::cout << "Pos: " << object->getPosition().x << " " << object->getPosition().y;
	std::cout << " Vel:" << object->getVelocity().x << " " << object->getVelocity().y << "\n";
}

void TextDebugDraw::drawLine(const pPhys::Vec2 &start, const pPhys::Vec2 &end) { }

void TextDebugDraw::logWarning(const std::string msg)
{
	std::cout << "[WARNING] " << msg.c_str() << "\n";
}

void TextDebugDraw::logDebug(const std::string msg)
{
	std::cout << "*DEBUG* " << msg.c_str() << "\n";
}

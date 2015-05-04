#pragma once

#include <SFML/Graphics.hpp>

#include <PropellerPhysics/pPhysDebugDrawInterface.h>

class SFMLDebugDraw : public pPhys::DebugDrawInterface
{
private:
	sf::RenderWindow *window;
public:
	SFMLDebugDraw();
	~SFMLDebugDraw();

	void logWarning(const std::string msg);
	void logDebug(const std::string msg);
	void drawLine(const pPhys::Vec2 &start, const pPhys::Vec2 &end) { }

	void drawCircle(const pPhys::Vec2 &pos, const float size);

	void flip();
};
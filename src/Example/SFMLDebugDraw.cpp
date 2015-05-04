#include <iostream>
#include <cmath>

#include <PropellerPhysics/pPhysObject.h>

#include "SFMLDebugDraw.h"

SFMLDebugDraw::SFMLDebugDraw()
{
	window = new sf::RenderWindow(sf::VideoMode(1200, 800), "PropellerPhysics");

	sf::View view;

	view.setCenter(0.f, 0.f);

	window->setView(view);
}

SFMLDebugDraw::~SFMLDebugDraw()
{
	delete window;
}

void SFMLDebugDraw::logWarning(const std::string msg)
{
	std::cout << "[WARNING] " << msg.c_str() << "\n";
}

void SFMLDebugDraw::logDebug(const std::string msg)
{
	std::cout << "*DEBUG* " << msg.c_str() << "\n";
}

void SFMLDebugDraw::drawCircle(const pPhys::Vec2 &pos, const float size)
{
	float scale = 1;

	sf::CircleShape shape(size * scale);
	shape.setFillColor(sf::Color::Green);

	shape.setPosition(pos.x * scale, -(pos.y * scale));

	window->draw(shape);
}

void SFMLDebugDraw::flip()
{
	window->display();
	window->clear();
}

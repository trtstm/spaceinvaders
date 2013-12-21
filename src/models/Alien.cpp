#include "Alien.hpp"

Alien::Alien(Coordinate position, double speed)
	: Entity(1, position, speed, sf::Rect<double>(0.0, 0.0, 16.0, 16.0))
{
}

Alien::~Alien()
{
}

void Alien::moveDown(double dt)
{
	auto newPosition = getPosition();
	newPosition.y += 16 * dt;

	setPosition(newPosition);
}

#include "Spaceship.hpp"

Spaceship::Spaceship(Coordinate position, double speed)
	: Entity(1, position, speed, sf::Rect<double>(0.0, 0.0, 48.0, 21.0))
{
}

Spaceship::~Spaceship()
{
}

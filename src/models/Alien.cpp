#include "Alien.hpp"

Alien::Alien(Coordinate position)
	: Entity(1, position, 16, sf::Rect<double>(0.0, 0.0, 16.0, 16.0))
{
}

Alien::~Alien()
{
}

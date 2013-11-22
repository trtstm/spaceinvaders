#include "Movable.hpp"

Movable::Movable()
	: Component(MOVABLE), location(Coordinate(0, 0))
{
}

void Movable::moveLeft()
{
	location.x -= 1;
}

void Movable::moveRight()
{
	location.x += 1;
}

void Movable::moveUp()
{
	location.y -= 1;
}

void Movable::moveDown()
{
	location.y += 1;
}

Coordinate Movable::getLocation() const
{
	return location;
}

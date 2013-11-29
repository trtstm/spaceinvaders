#include "Movable.hpp"

#include "MoveMessage.hpp"

Movable::Movable()
	: Component(MOVABLE), location(Coordinate(0, 0))
{
}

void Movable::moveLeft()
{
	auto newLocation = location;
	newLocation.x -= 1;

	setLocation(newLocation);
}

void Movable::moveRight()
{
	auto newLocation = location;
	newLocation.x += 1;

	setLocation(newLocation);
}

void Movable::moveUp()
{
	auto newLocation = location;
	newLocation.y -= 1;

	setLocation(newLocation);
}

void Movable::moveDown()
{
	auto newLocation = location;
	newLocation.y += 1;

	setLocation(newLocation);
}

void Movable::setLocation(Coordinate location)
{
	auto oldLocation = this->location;

	this->location = location;

	MoveMessage msg(0, oldLocation, this->location);
	notifyObservers(msg);
}

Coordinate Movable::getLocation() const
{
	return location;
}

#include "Movable.hpp"

#include "MoveMessage.hpp"

Movable::Movable()
	: Component(MOVABLE), location(Coordinate(0, 0))
{
}

void Movable::moveLeft(double dt)
{
	auto newLocation = location;
	newLocation.x -= 800 * dt;

	setLocation(newLocation);
}

void Movable::moveRight(double dt)
{
	auto newLocation = location;
	newLocation.x += 800 * dt;

	setLocation(newLocation);
}

void Movable::moveUp(double dt)
{
	auto newLocation = location;
	newLocation.y -= 800 * dt;

	setLocation(newLocation);
}

void Movable::moveDown(double dt)
{
	auto newLocation = location;
	newLocation.y += 800 * dt;

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

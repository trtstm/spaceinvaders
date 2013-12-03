#include "Movable.hpp"

#include "messages/MoveMessage.hpp"

Movable::Movable()
	: Component(MOVABLE), location(Coordinate(0, 0)), speed(100)
{
}

Movable::Movable(Coordinate location, double speed)
	: Component(MOVABLE), location(location), speed(speed)
{
}

void Movable::moveLeft(double dt)
{
	auto newLocation = location;
	newLocation.x -= speed * dt;

	setLocation(newLocation);
}

void Movable::moveRight(double dt)
{
	auto newLocation = location;
	newLocation.x += speed * dt;

	setLocation(newLocation);
}

void Movable::moveUp(double dt)
{
	auto newLocation = location;
	newLocation.y -= speed * dt;

	setLocation(newLocation);
}

void Movable::moveDown(double dt)
{
	auto newLocation = location;
	newLocation.y += speed * dt;

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
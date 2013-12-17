#include "Movable.hpp"

#include "messages/MoveMessage.hpp"

Movable::Movable(int entity, Coordinate position, double speed)
	: Component(MOVABLE, entity), position(position), speed(speed)
{
}

Movable::~Movable()
{
}

void Movable::moveLeft(double dt)
{
	auto newPosition = position;
	newPosition.x -= speed * dt;

	setPosition(newPosition);
}

void Movable::moveRight(double dt)
{
	auto newPosition = position;
	newPosition.x += speed * dt;

	setPosition(newPosition);
}

void Movable::moveUp(double dt)
{
	auto newPosition = position;
	newPosition.y -= speed * dt;

	setPosition(newPosition);
}

void Movable::moveDown(double dt)
{
	auto newPosition = position;
	newPosition.y += speed * dt;

	setPosition(newPosition);
}

void Movable::setPosition(Coordinate position)
{
	auto oldPosition = this->position;

	this->position = position;

	MoveMessage msg(entity, oldPosition, this->position);
	notifyObservers(msg);
}

Coordinate Movable::getPosition() const
{
	return position;
}

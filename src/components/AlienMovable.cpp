#include "AlienMovable.hpp"

#include "messages/MoveMessage.hpp"

AlienMovable::AlienMovable(int entity, Coordinate location)
	: Movable(entity, location, 16)
{
}

void AlienMovable::moveLeft(double dt)
{
	auto newPosition = position;
	newPosition.x -= speed * dt;
	if(newPosition.x - 16 / 2 < 0) {
		newPosition.x = 16 / 2;
	}

	setPosition(newPosition);
}

void AlienMovable::moveRight(double dt)
{
	auto newPosition = position;
	newPosition.x += speed * dt;
	if(newPosition.x + 16 / 2 > 800) {
		newPosition.x = 800 - 16 / 2;
	}

	setPosition(newPosition);
}

void AlienMovable::moveDown(double dt)
{
	auto newPosition = position;
	newPosition.y += speed * dt;
	if(newPosition.y + 16 / 2 > 600) {
		newPosition.y = 600 - 16 / 2;
	}

	setPosition(newPosition);
}


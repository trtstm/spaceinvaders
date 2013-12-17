#include "SpaceshipMovable.hpp"

#include "messages/MoveMessage.hpp"

SpaceshipMovable::SpaceshipMovable(int entity, Coordinate position, double speed)
	: Movable(entity, position, speed)
{
}

void SpaceshipMovable::moveLeft(double dt)
{
	auto newPosition = position;
	newPosition.x -= speed * dt;
	if(newPosition.x - 120 / 2 < 0) {
		newPosition.x = 120 / 2;
	}

	setPosition(newPosition);
}

void SpaceshipMovable::moveRight(double dt)
{
	auto newPosition = position;
	newPosition.x += speed * dt;
	if(newPosition.x + 120 / 2 > 800) {
		newPosition.x = 800 - 120 / 2;
	}

	setPosition(newPosition);
}

void SpaceshipMovable::moveUp(double dt)
{

}

void SpaceshipMovable::moveDown(double dt)
{

}


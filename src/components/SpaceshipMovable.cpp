#include "SpaceshipMovable.hpp"

#include "messages/MoveMessage.hpp"

SpaceshipMovable::SpaceshipMovable(std::shared_ptr<Entity> entity, Coordinate location, double speed)
	: Movable(entity, location, speed)
{
}

void SpaceshipMovable::moveLeft(double dt)
{
	auto newLocation = location;
	newLocation.x -= speed * dt;
	if(newLocation.x - 120 / 2 < 0) {
		newLocation.x = 120 / 2;
	}

	setLocation(newLocation);
}

void SpaceshipMovable::moveRight(double dt)
{
	auto newLocation = location;
	newLocation.x += speed * dt;
	if(newLocation.x + 120 / 2 > 800) {
		newLocation.x = 800 - 120 / 2;
	}

	setLocation(newLocation);
}

void SpaceshipMovable::moveUp(double dt)
{

}

void SpaceshipMovable::moveDown(double dt)
{

}


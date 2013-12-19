#include "SpaceshipController.hpp"

#include "components/Movable.hpp"
#include "components/Livable.hpp"

#include "messages/DiedMessage.hpp"
#include "messages/BulletHitMessage.hpp"

SpaceshipController::SpaceshipController(Spaceship& spaceship)
	: spaceship(&spaceship)
{
}

void SpaceshipController::moveLeft(double dt)
{
	spaceship->moveLeft(dt);
}

void SpaceshipController::moveRight(double dt)
{
	spaceship->moveRight(dt);
}

Coordinate SpaceshipController::getPosition()
{
	return spaceship->getPosition();
}

bool SpaceshipController::isAlive() const
{
	return (spaceship->getHealth() > 0.0);
}

bool SpaceshipController::notify(Message& msg)
{

}

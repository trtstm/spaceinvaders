#include "SpaceshipController.hpp"

namespace Controller {

SpaceshipController::SpaceshipController(Model::Spaceship* spaceship)
	: spaceship(spaceship)
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

void SpaceshipController::moveDown(double dt)
{
	spaceship->moveDown(dt);
}

Coordinate SpaceshipController::getPosition()
{
	return spaceship->getPosition();
}


void SpaceshipController::setPosition(Coordinate position)
{
	spaceship->setPosition(position);
}

void SpaceshipController::update(double dt)
{
	(void)dt;
}

bool SpaceshipController::isAlive() const
{

	return (spaceship->getHealth() > 0.0);
}

Model::Spaceship& SpaceshipController::getSpaceship()
{
	return *spaceship;
}

}

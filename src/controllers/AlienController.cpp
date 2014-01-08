#include "AlienController.hpp"

#include "messages/DiedMessage.hpp"
#include "messages/BulletHitMessage.hpp"

namespace Controller {

AlienController::AlienController(Model::Alien* alien)
	: alien(alien), direction(LEFT)
{
}

void AlienController::moveLeft(double dt)
{
	alien->moveLeft(dt);
}

void AlienController::moveRight(double dt)
{
	alien->moveRight(dt);
}

void AlienController::moveDown(double dt)
{
	alien->moveDown(dt);
}

Coordinate AlienController::getPosition()
{
	return alien->getPosition();
}


void AlienController::setPosition(Coordinate position)
{
	alien->setPosition(position);
}

Direction AlienController::getDirection() const
{
	return direction;
}

void AlienController::setDirection(Direction dir)
{
	direction = dir;
}

void AlienController::update(double dt)
{
	switch(direction) {
		case LEFT:
			alien->moveLeft(dt);
			break;

		case RIGHT:
			alien->moveRight(dt);
			break;

		case UP:
			alien->moveUp(dt);
			break;

		case DOWN:
			alien->moveDown(dt);
			break;
	}
}

bool AlienController::isAlive() const
{

	return (alien->getHealth() > 0.0);
}

Model::Alien& AlienController::getAlien()
{
	return *alien;
}

}

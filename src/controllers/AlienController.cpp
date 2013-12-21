#include "AlienController.hpp"

#include "components/Movable.hpp"
#include "components/Livable.hpp"

#include "messages/DiedMessage.hpp"
#include "messages/BulletHitMessage.hpp"

AlienController::AlienController(Alien alien)
	: alien(alien), direction(LEFT)
{
}

void AlienController::moveLeft(double dt)
{
	alien.moveLeft(dt);
}

void AlienController::moveRight(double dt)
{
	alien.moveRight(dt);
}

void AlienController::moveDown(double dt)
{
	alien.moveDown(dt);
}

Coordinate AlienController::getPosition()
{
	return alien.getPosition();
}


void AlienController::setPosition(Coordinate position)
{
	alien.setPosition(position);
}

Direction AlienController::getDirection()
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
			alien.moveLeft(dt);
			break;

		case RIGHT:
			alien.moveRight(dt);
			break;

		case UP:
			alien.moveUp(dt);
			break;

		case DOWN:
			alien.moveDown(dt);
			break;
	}
}

bool AlienController::isAlive() const
{

	return (alien.getHealth() > 0.0);
}

Alien& AlienController::getAlien()
{
	return alien;
}

bool AlienController::notify(Message& msg)
{
	switch(msg.type) {
		case BULLETHIT:
		{
			if(!isAlive()) {
				break;
			}

			auto& bulletHitMsg = static_cast<BulletHitMessage&>(msg);

			// Only listen to bullets that hit us.
			if(alien.getId() != bulletHitMsg.subject) {
				break;
			}

			alien.doDamage(1);
		}
	}
}

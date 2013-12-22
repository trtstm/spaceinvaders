#include "SpaceshipController.hpp"

#include "messages/DiedMessage.hpp"
#include "messages/BulletHitMessage.hpp"

SpaceshipController::SpaceshipController(Spaceship spaceship)
	: spaceship(spaceship)
{
}

void SpaceshipController::moveLeft(double dt)
{
	spaceship.moveLeft(dt);
}

void SpaceshipController::moveRight(double dt)
{
	spaceship.moveRight(dt);
}

void SpaceshipController::moveDown(double dt)
{
	spaceship.moveDown(dt);
}

Coordinate SpaceshipController::getPosition()
{
	return spaceship.getPosition();
}


void SpaceshipController::setPosition(Coordinate position)
{
	spaceship.setPosition(position);
}

void SpaceshipController::update(double dt)
{

}

bool SpaceshipController::isAlive() const
{

	return (spaceship.getHealth() > 0.0);
}

Spaceship& SpaceshipController::getSpaceship()
{
	return spaceship;
}

bool SpaceshipController::notify(Message& msg)
{
	switch(msg.type) {
		case BULLETHIT:
		{
			if(!isAlive()) {
				break;
			}

			auto& bulletHitMsg = static_cast<BulletHitMessage&>(msg);

			// Only listen to bullets that hit us.
			if(spaceship.getId() != bulletHitMsg.subject) {
				break;
			}

			spaceship.doDamage(1);
		}
	}

	return true;
}

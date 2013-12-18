#include "AlienController.hpp"

#include "components/Movable.hpp"
#include "components/Livable.hpp"

#include "messages/DiedMessage.hpp"
#include "messages/BulletHitMessage.hpp"

AlienController::AlienController(std::shared_ptr<Alien> alien)
	: alien(alien), direction(LEFT)
{
}

void AlienController::moveLeft(double dt)
{
	alien->getMovable().moveLeft(dt);
}

void AlienController::moveRight(double dt)
{
	alien->getMovable().moveRight(dt);
}

void AlienController::moveDown(double dt)
{
	alien->getMovable().moveDown(dt);
}

Coordinate AlienController::getPosition()
{
	return alien->getMovable().getPosition();
}


void AlienController::setPosition(Coordinate position)
{
	alien->getMovable().setPosition(position);
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
				alien->getMovable().moveLeft(dt);
			break;

		case RIGHT:
				alien->getMovable().moveRight(dt);
			break;

		case DOWN:
				alien->getMovable().moveDown(dt);
			break;
	}
}

bool AlienController::isAlive() const
{
	auto& livable = alien->getLivable();

	return (livable.getHealth() > 0.0);
}

bool AlienController::notify(Message& msg)
{
	switch(msg.type) {
		case BULLETHIT:
		{
			auto bulletHitMessage = static_cast<BulletHitMessage&>(msg);
			if(bulletHitMessage.subject != alien->getId()) {
				break;
			}
	
			auto& livable = alien->getLivable();

			livable.doDamage(1);

			break;
		}
		case DIED:
		{
			auto diedMessage = static_cast<DiedMessage&>(msg);
			if(diedMessage.entity != alien->getId()) {
				break;
			}
	
			std::cout << "Entity" << alien->getId() << ": died" << std::endl;

			break;
		}
	};
}

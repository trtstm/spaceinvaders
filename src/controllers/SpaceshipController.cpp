#include "SpaceshipController.hpp"

#include "components/Movable.hpp"
#include "components/Livable.hpp"

#include "messages/DiedMessage.hpp"
#include "messages/BulletHitMessage.hpp"

SpaceshipController::SpaceshipController(std::shared_ptr<Spaceship> spaceship)
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

Coordinate SpaceshipController::getLocation()
{
	return spaceship->getComponent<Movable>()->getLocation();
}

bool SpaceshipController::isAlive() const
{
	auto livable = spaceship->getComponent<Livable>();
	if(!livable) {
		return false;
	}

	return (livable->getHealth() > 0.0);
}

bool SpaceshipController::notify(Message& msg)
{
	switch(msg.type) {
		case BULLETHIT:
		{
			auto bulletHitMessage = static_cast<BulletHitMessage&>(msg);
			if(bulletHitMessage.subject != spaceship->getId()) {
				break;
			}
	
			if(bulletHitMessage.subject == spaceship->getId()) {
				auto livable = spaceship->getComponent<Livable>();
				if(!livable) {
					break;
				}
			std::cout << "We got hit" << std::endl;
				livable->doDamage(1);
			}

			break;
		}
	};
}

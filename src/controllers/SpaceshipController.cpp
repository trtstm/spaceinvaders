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

bool SpaceshipController::notify(Message& msg)
{
	switch(msg.type) {
		case DIED:
		{
			auto diedMsg = static_cast<DiedMessage&>(msg);
	
			if(diedMsg.entity == spaceship->getId()) {
				std::cout << "We died" << std::endl;
			}

			break;
		}

		case BULLETHIT:
		{
			auto bulletHitMsg = static_cast<BulletHitMessage&>(msg);
	
			if(bulletHitMsg.subject == spaceship->getId()) {
				auto livable = spaceship->getComponent<Livable>();
				if(!livable) {
					break;
				}

				livable->doDamage(1);
			}

			break;
		}
	};
}

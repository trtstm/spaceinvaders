#include "AlienController.hpp"

#include "components/Movable.hpp"
#include "components/Livable.hpp"

#include "messages/DiedMessage.hpp"
#include "messages/BulletHitMessage.hpp"

AlienController::AlienController(std::shared_ptr<Alien> alien)
	: alien(alien)
{
}

Coordinate AlienController::getLocation()
{
	return alien->getMovable().getLocation();
}

bool AlienController::isAlive() const
{
	auto livable = alien->getLivable();

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
	
			auto livable = alien->getLivable();

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

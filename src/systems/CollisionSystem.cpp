#include <iostream>

#include "CollisionSystem.hpp"
#include "components/Collidable.hpp"
#include "messages/MoveMessage.hpp"

void CollisionSystem::addEntity(std::shared_ptr<Entity> entity)
{
	entities.erase(entity);
	entities.insert(entity);
}

void CollisionSystem::removeEntity(std::shared_ptr<Entity> entity)
{
	entities.erase(entity);
}

bool CollisionSystem::notify(Message& msg)
{
	switch(msg.getType()) {
		case MOVE:
		{
			auto moveMsg = static_cast<MoveMessage&>(msg);

			if(moveMsg.getEntity()->getComponent<Collidable>()) {
				if(moveMsg.newPosition.y < 100) {
					moveMsg.getEntity()->getComponent<Collidable>()->onCollision();
				}

			}

			break;
		}
	};

	return true;
}

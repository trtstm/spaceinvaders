#include <iostream>

#include "CollisionSystem.hpp"
#include "components/Collidable.hpp"
#include "messages/MoveMessage.hpp"

void CollisionSystem::addEntity(std::shared_ptr<Entity> entity)
{
	entities.erase(entity->getId());
	entities[entity->getId()] = entity;
}

void CollisionSystem::removeEntity(std::shared_ptr<Entity> entity)
{
	entities.erase(entity->getId());
}

bool CollisionSystem::notify(Message& msg)
{
	auto sender = entities[msg.entity];
	auto senderCollidable = sender->getComponent<Collidable>();
	if(!senderCollidable) {
		return true;
	}
	auto senderMovable = sender->getComponent<Movable>();
	if(!senderMovable) {
		return true;
	}

	switch(msg.type) {
		case MOVE:
		{
			for(auto& entity : entities) {
				if(sender->getId() == entity.second->getId()) {
					break;
				}	

				auto subject = entity.second;
				auto subjectCollidable = subject->getComponent<Collidable>();
				if(!subjectCollidable) {
					break;
				}
				auto subjectMovable = subject->getComponent<Movable>();
				if(!subjectMovable) {
					break;
				}


				auto senderRect = senderCollidable->getRect();	
				senderRect.left = senderMovable->getLocation().x - senderRect.width / 2;
				senderRect.top = senderMovable->getLocation().y - senderRect.height / 2;

				auto subjectRect = subjectCollidable->getRect();	
				subjectRect.left = subjectMovable->getLocation().x - subjectRect.width / 2;
				subjectRect.top = subjectMovable->getLocation().y - subjectRect.height / 2;

				if(senderRect.intersects(subjectRect)) {
					senderCollidable->onCollision(subject->getId());
				}
			}
			break;
		}
	}

	return true;
}

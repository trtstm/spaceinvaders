#include <iostream>

#include "CollisionSystem.hpp"
#include "components/Collidable.hpp"
#include "messages/MoveMessage.hpp"

void CollisionSystem::addEntity(std::shared_ptr<Entity> entity)
{
	entities.erase(entity->getId());
	entities[entity->getId()] = entity;
}

void CollisionSystem::removeEntity(int entity)
{
	entities.erase(entity);
}

bool CollisionSystem::notify(Message& msg)
{
	// The sender has to be added with the addEntity method!
	auto sender = entities[msg.entity];
	auto& senderCollidable = sender->getCollidable();

	auto& senderMovable = sender->getMovable();
	switch(msg.type) {
		case MOVE:
		{
			for(auto& entity : entities) {
				if(sender->getId() == entity.second->getId()) {
					break;
				}	

				auto subject = entity.second;
				auto& subjectCollidable = subject->getCollidable();
				auto& subjectMovable = subject->getMovable();

				auto senderRect = senderCollidable.getRect();	
				senderRect.left = senderMovable.getPosition().x - senderRect.width / 2;
				senderRect.top = senderMovable.getPosition().y - senderRect.height / 2;

				auto subjectRect = subjectCollidable.getRect();	
				subjectRect.left = subjectMovable.getPosition().x - subjectRect.width / 2;
				subjectRect.top = subjectMovable.getPosition().y - subjectRect.height / 2;

				if(senderRect.intersects(subjectRect)) {
					senderCollidable.onCollision(subject->getId());
				}
			}
			break;
		}
	}

	return true;
}

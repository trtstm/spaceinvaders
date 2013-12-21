#include <iostream>

#include "CollisionSystem.hpp"
#include "components/Collidable.hpp"
#include "messages/MoveMessage.hpp"

CollisionSystem::~CollisionSystem()
{
}

void CollisionSystem::addEntity(Entity& entity, bool registerMove)
{
	entities.erase(entity.getId());
	entities[entity.getId()] = &entity;

	if(registerMove) {
		entity.registerMove(*this);
	}
}

void CollisionSystem::removeEntity(int entity)
{
	if(entities.count(entity) > 0) {
		entities[entity]->unRegisterMove(*this);
	}

	entities.erase(entity);
}

bool CollisionSystem::notify(Message& msg)
{
	// The sender has to be added with the addEntity method!
	auto sender = entities[msg.entity];

	switch(msg.type) {
		case MOVE:
		{
			for(auto& entity : entities) {
				auto subject = entity.second;

				// Can't collide with ourself.
				if(sender->getId() == subject->getId()) {
					break;
				}


				auto senderRect = sender->getCollisionRectangle();	
				senderRect.left = sender->getPosition().x - senderRect.width / 2;
				senderRect.top = sender->getPosition().y - senderRect.height / 2;

				auto subjectRect = subject->getCollisionRectangle();	
				subjectRect.left = subject->getPosition().x - subjectRect.width / 2;
				subjectRect.top = subject->getPosition().y - subjectRect.height / 2;

				if(senderRect.intersects(subjectRect)) {
					sender->onCollision(subject->getId());
				}
			}
			break;
		}
	}

	return true;
}

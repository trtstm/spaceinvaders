#include <iostream>

#include "CollisionSystem.hpp"
#include "messages/MoveMessage.hpp"
#include "messages/DiedMessage.hpp"

CollisionSystem::~CollisionSystem()
{
}

void CollisionSystem::addEntity(Entity& entity, bool registerMove)
{
	switch(entity.getType()) {
		case BULLET:
			bullets.erase(entity.getId());
			bullets[entity.getId()] = &static_cast<Bullet&>(entity);
			break;

		case ALIEN:
			aliens.erase(entity.getId());
			aliens[entity.getId()] = &static_cast<Alien&>(entity);
			break;

		case SPACESHIP:
			spaceships.erase(entity.getId());
			spaceships[entity.getId()] = &static_cast<Spaceship&>(entity);
			break;

		case LASERCANNON:
			laserCannons.erase(entity.getId());
			laserCannons[entity.getId()] = &static_cast<LaserCannon&>(entity);
			break;

		case BUNKER:
			bunkers.erase(entity.getId());
			bunkers[entity.getId()] = &entity;
			break;

		default:
			rest.erase(entity.getId());
			rest[entity.getId()] = &entity;
	}

	if(registerMove) {
		entity.registerMove(*this);
	}
}

void CollisionSystem::removeEntity(Entity& entity)
{
	switch(entity.getType()) {
		case BULLET:
			if(bullets.count(entity.getId()) != 1) {
				break;
			}

			bullets[entity.getId()]->unRegisterMove(*this);
			bullets.erase(entity.getId());
			break;

		case ALIEN:
			if(aliens.count(entity.getId()) != 1) {
				break;
			}

			aliens[entity.getId()]->unRegisterMove(*this);
			aliens.erase(entity.getId());
			break;

		case SPACESHIP:
			if(spaceships.count(entity.getId()) != 1) {
				break;
			}

			spaceships[entity.getId()]->unRegisterMove(*this);
			spaceships.erase(entity.getId());
			break;

		case LASERCANNON:
			if(laserCannons.count(entity.getId()) != 1) {
				break;
			}

			laserCannons[entity.getId()]->unRegisterMove(*this);
			laserCannons.erase(entity.getId());
			break;

		case BUNKER:
			if(bunkers.count(entity.getId()) != 1) {
				break;
			}

			bunkers[entity.getId()]->unRegisterMove(*this);
			bunkers.erase(entity.getId());
			break;

		default:
			if(rest.count(entity.getId()) != 1) {
				break;
			}

			rest.erase(entity.getId());
			rest[entity.getId()] = &entity;
	}
}

bool CollisionSystem::notify(Message& msg)
{
	// The sender has to be added with the addEntity method!
	auto sender = findEntity(msg.entity);

	switch(msg.type) {
		case MOVE:
		{
			if(sender->getType() == BULLET) {
				for(auto& laserCannon : laserCannons) {
					if(hasCollision(sender, laserCannon.second)) {
						sender->onCollision(laserCannon.second);
						laserCannon.second->onCollision(sender);
					}
				}

				for(auto& alien : aliens) {
					if(hasCollision(sender, alien.second)) {
						sender->onCollision(alien.second);
						alien.second->onCollision(sender);
					}
				}

				for(auto& bunker : bunkers) {
					if(hasCollision(sender, bunker.second)) {
						sender->onCollision(bunker.second);
						bunker.second->onCollision(sender);
					}
				}

				for(auto& spaceship : spaceships) {
					if(hasCollision(sender, spaceship.second)) {
						sender->onCollision(spaceship.second);
						spaceship.second->onCollision(sender);
					}
				}
			}

			break;
		}

		default:
			break;
	}

	return true;
}

Entity* CollisionSystem::findEntity(int id)
{
	if(bullets.count(id) == 1) {
		return bullets[id];
	}

	if(aliens.count(id) == 1) {
		return aliens[id];
	}

	if(spaceships.count(id) == 1) {
		return spaceships[id];
	}

	if(laserCannons.count(id) == 1) {
		return laserCannons[id];
	}

	if(bunkers.count(id) == 1) {
		return bunkers[id];
	}

	if(rest.count(id) == 1) {
		return rest[id];
	}

	return 0;
}

bool CollisionSystem::hasCollision(Entity* sender, Entity* subject)
{
	if(sender->getId() == subject->getId()) {
		return false;
	}

	auto senderRect = sender->getCollisionRectangle();	
	senderRect.left = sender->getPosition().x - senderRect.width / 2;
	senderRect.top = sender->getPosition().y - senderRect.height / 2;

	auto subjectRect = subject->getCollisionRectangle();	
	subjectRect.left = subject->getPosition().x - subjectRect.width / 2;
	subjectRect.top = subject->getPosition().y - subjectRect.height / 2;

	if(senderRect.intersects(subjectRect)) {
		return true;
	}

	return false;
}

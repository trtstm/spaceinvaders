#include "BulletCollidable.hpp"

#include "messages/BulletHitMessage.hpp"

BulletCollidable::BulletCollidable(int entity)
	: Collidable(entity)
{
}

void BulletCollidable::checkCollision(std::shared_ptr<Entity> subject)
{
	BulletHitMessage msg(entity, subject->getId());
	notifyObservers(msg);
}

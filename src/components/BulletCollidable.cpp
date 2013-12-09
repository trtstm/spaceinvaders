#include "BulletCollidable.hpp"

#include "messages/BulletHitMessage.hpp"

BulletCollidable::BulletCollidable(std::shared_ptr<Entity> entity)
	: Collidable(entity)
{
}

void BulletCollidable::checkCollision(std::shared_ptr<Entity> subject)
{
	BulletHitMessage msg(getEntity(), subject);
	notifyObservers(msg);
}

#include "Collidable.hpp"

#include "messages/CollisionMessage.hpp"

Collidable::Collidable(std::shared_ptr<Entity> entity)
	: Component(COLLIDABLE, entity)
{
}

void Collidable::checkCollision(std::shared_ptr<Entity> subject)
{
	CollisionMessage msg(getEntity());
	notifyObservers(msg);
}

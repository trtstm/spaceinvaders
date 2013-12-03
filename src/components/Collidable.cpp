#include "Collidable.hpp"

#include "messages/CollisionMessage.hpp"

Collidable::Collidable(std::shared_ptr<Entity> entity)
	: Component(COLLIDABLE, entity)
{
}

void Collidable::onCollision()
{
	CollisionMessage msg(getEntity());
	notifyObservers(msg);
}

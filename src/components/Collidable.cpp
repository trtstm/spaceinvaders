#include "Collidable.hpp"

#include "messages/CollisionMessage.hpp"

Collidable::Collidable(int entity)
	: Component(COLLIDABLE, entity)
{
}

void Collidable::checkCollision(std::shared_ptr<Entity> subject)
{

}

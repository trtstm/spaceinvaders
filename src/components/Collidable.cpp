#include <SFML/Graphics/Rect.hpp>

#include "Collidable.hpp"

#include "messages/CollisionMessage.hpp"

Collidable::Collidable(int entity, sf::Rect<double> rect)
	: Component(COLLIDABLE, entity), rect(rect), collided(false)
{
}

Collidable::~Collidable()
{
}

void Collidable::onCollision(int subject)
{
	collided = true;

	CollisionMessage msg(entity);
	notifyObservers(msg);
}

bool Collidable::hasCollided() const
{
	return collided;
}

sf::Rect<double> Collidable::getRect() const
{
	return rect;
}

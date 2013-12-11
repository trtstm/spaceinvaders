#include <SFML/Graphics/Rect.hpp>

#include "Collidable.hpp"

#include "messages/CollisionMessage.hpp"

Collidable::Collidable(int entity, sf::Rect<double> rect)
	: Component(COLLIDABLE, entity), rect(rect)
{
}

void Collidable::onCollision(int subject)
{
	CollisionMessage msg(entity);
	notifyObservers(msg);
}

sf::Rect<double> Collidable::getRect() const
{
	return rect;
}

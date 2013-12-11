#include <iostream>

#include "BulletCollidable.hpp"

#include "messages/BulletHitMessage.hpp"

BulletCollidable::BulletCollidable(int entity, sf::Rect<double> rect)
	: Collidable(entity, rect)
{
}

void BulletCollidable::onCollision(int subject)
{
	if(entity == subject) {
		return;
	}

	BulletHitMessage msg(entity, subject);
	notifyObservers(msg);
}

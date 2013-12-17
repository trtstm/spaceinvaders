#include <iostream>

#include "BulletCollidable.hpp"

#include "messages/BulletHitMessage.hpp"

BulletCollidable::BulletCollidable(int entity, int bulletOwner, sf::Rect<double> rect)
	: Collidable(entity, rect), bulletOwner(bulletOwner)
{
}

void BulletCollidable::onCollision(int subject)
{
	if(bulletOwner == subject) {
		return;
	}

	collided = true;

	BulletHitMessage msg(entity, subject);
	notifyObservers(msg);
}

#include <iostream>

#include "Bullet.hpp"

#include "messages/BulletHitMessage.hpp"

Bullet::Bullet(Coordinate position, int owner)
	: Entity(1, position, 300, sf::Rect<double>(0.0, 0.0, 4.0, 10.0)), owner(owner)
{
}

Bullet::~Bullet()
{
}

void Bullet::onCollision(int collidee)
{
	if(owner != collidee) {
		auto msg = BulletHitMessage(getId(), collidee);
		notifyObservers(msg);

		doDamage(1);
	}
}

int Bullet::getOwner() const
{
	return owner;
}

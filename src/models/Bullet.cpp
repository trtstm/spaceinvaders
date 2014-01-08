#include <iostream>

#include "Bullet.hpp"

#include "messages/BulletHitMessage.hpp"

namespace Model {

Bullet::Bullet(Coordinate position, double speed, int owner)
	: Entity(BULLET, 1, position, speed, sf::Rect<double>(0.0, 0.0, 4.0, 10.0)), owner(owner)
{
}

Bullet::~Bullet()
{
}

void Bullet::onCollision(const Entity* entity)
{
	if(owner != entity->getId()) {
		auto msg = Message::BulletHitMessage(getId(), entity->getId());
		notifyCollision(msg);

		doDamage(1);
	}
}

int Bullet::getOwner() const
{
	return owner;
}

}

#include <iostream>

#include "Bullet.hpp"

#include "messages/BulletHitMessage.hpp"

namespace Model {

Bullet::Bullet(Coordinate position, double speed, Type type, int owner)
	: Entity(BULLET, 1, position, speed, sf::Rect<double>(0.0, 0.0, 4.0, 10.0)), type(type), owner(owner)
{
}

Bullet::~Bullet()
{
}

void Bullet::onCollision(const Entity* entity)
{
	if((entity->getType() == Model::LASERCANNON && type != FRIENDLY) || (entity->getType() != Model::LASERCANNON && entity->getId() != getOwner())) {
		auto msg = Message::BulletHitMessage(getId(), entity->getId());
		notifyCollision(msg);

		doDamage(1);
	}
}

int Bullet::getOwner() const
{
	return owner;
}

Bullet::Type Bullet::getType() const
{
	return type;
}

}

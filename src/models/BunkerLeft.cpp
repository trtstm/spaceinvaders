#include "BunkerLeft.hpp"

#include "Bullet.hpp"
#include "messages/BulletHitMessage.hpp"

BunkerLeft::BunkerLeft(Coordinate position)
	: Entity(BUNKER, 3, position, 0, sf::Rect<double>(0.0, 0.0, 10.0, 32.0))
{
}

BunkerLeft::~BunkerLeft()
{
}

void BunkerLeft::onCollision(const Entity* entity)
{
	if(entity->getType() == BULLET) {
		auto bullet = static_cast<const Bullet*>(entity);

		BulletHitMessage msg(entity->getId(), this->getId());

		notifyCollision(msg);

		doDamage(1);

	}


}
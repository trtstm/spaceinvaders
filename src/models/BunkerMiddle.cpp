#include "BunkerMiddle.hpp"

#include "Bullet.hpp"
#include "messages/BulletHitMessage.hpp"

BunkerMiddle::BunkerMiddle(Coordinate position)
	: Entity(BUNKER, 3, position, 0, sf::Rect<double>(0.0, 0.0, 22.0, 28.0))
{
}

BunkerMiddle::~BunkerMiddle()
{
}

void BunkerMiddle::onCollision(const Entity* entity)
{
	if(entity->getType() == BULLET) {
		auto bullet = static_cast<const Bullet*>(entity);

		BulletHitMessage msg(entity->getId(), this->getId());

		notifyCollision(msg);

		doDamage(1);

	}


}

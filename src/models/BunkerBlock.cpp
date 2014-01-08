#include "BunkerBlock.hpp"

#include "Bullet.hpp"
#include "messages/BulletHitMessage.hpp"

namespace Model {

BunkerBlock::BunkerBlock(Coordinate position, const sf::Rect<double>& collisionRectangle)
	: Entity(BUNKER, 3, position, 0, collisionRectangle)
{
}

BunkerBlock::~BunkerBlock()
{
}

void BunkerBlock::onCollision(const Entity* entity)
{
	if(entity->getType() == BULLET) {
		//auto bullet = static_cast<const Bullet*>(entity);

		Message::BulletHitMessage msg(entity->getId(), this->getId());

		notifyCollision(msg);

		doDamage(1);

	}
}

}

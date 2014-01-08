#include "BunkerLeft.hpp"

#include "Bullet.hpp"
#include "messages/BulletHitMessage.hpp"

namespace Model {

BunkerLeft::BunkerLeft(Coordinate position)
	: BunkerBlock(position, sf::Rect<double>(0.0, 0.0, 10.0, 32.0))
{
}

BunkerLeft::~BunkerLeft()
{
}
}

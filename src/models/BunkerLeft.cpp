#include "BunkerLeft.hpp"

#include "Bullet.hpp"
#include "messages/BulletHitMessage.hpp"

namespace Model {

BunkerLeft::BunkerLeft(Coordinate position, double width, double height)
	: BunkerBlock(position, sf::Rect<double>(0.0, 0.0, width, height))
{
}

BunkerLeft::~BunkerLeft()
{
}
}

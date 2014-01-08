#include "BunkerRight.hpp"

#include "Bullet.hpp"
#include "messages/BulletHitMessage.hpp"

namespace Model {

BunkerRight::BunkerRight(Coordinate position)
	: BunkerBlock(position, sf::Rect<double>(0.0, 0.0, 10.0, 32.0))
{
}

BunkerRight::~BunkerRight()
{
}

}

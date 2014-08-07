#include "BunkerRight.hpp"

#include "Bullet.hpp"
#include "messages/BulletHitMessage.hpp"

namespace Model {

BunkerRight::BunkerRight(Coordinate position, double width, double height)
	: BunkerBlock(position, sf::Rect<double>(0.0, 0.0, width, height))
{
}

BunkerRight::~BunkerRight()
{
}

}

#include "BunkerMiddle.hpp"

#include "Bullet.hpp"
#include "messages/BulletHitMessage.hpp"

namespace Model {

BunkerMiddle::BunkerMiddle(Coordinate position, double width, double height)
	: BunkerBlock(position, sf::Rect<double>(0.0, 0.0, width, height))
{
}

BunkerMiddle::~BunkerMiddle()
{
}

}

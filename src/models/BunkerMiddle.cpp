#include "BunkerMiddle.hpp"

#include "Bullet.hpp"
#include "messages/BulletHitMessage.hpp"

namespace Model {

BunkerMiddle::BunkerMiddle(Coordinate position)
	: BunkerBlock(position, sf::Rect<double>(0.0, 0.0, 22.0, 28.0))
{
}

BunkerMiddle::~BunkerMiddle()
{
}

}

#include <memory>

#include "LaserCannon.hpp"

#include "Bullet.hpp"

LaserCannon::LaserCannon(Coordinate position)
	: Entity(LASERCANNON, 3, position, 400, sf::Rect<double>(0.0, 0.0, 26.0, 15.0))
{
}

LaserCannon::~LaserCannon()
{
}

void LaserCannon::onCollision(const Entity* entity)
{
	if(entity->getType() == BULLET) {
		auto bullet = static_cast<const Bullet*>(entity);

		if(bullet->getOwner() == this->getId()) {
			return;
		}

		this->doDamage(1);
		this->setPosition(Coordinate(400,580));
	}
	else if(entity->getType() == ALIEN) {
		this->doDamage(this->getHealth());
	}


}

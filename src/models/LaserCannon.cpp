#include <memory>

#include "LaserCannon.hpp"

#include "Bullet.hpp"

namespace Model {

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

void LaserCannon::moveLeft(double dt)
{
	Coordinate newPos = this->getPosition();
	newPos.x -= this->getSpeed() * dt;

	if(newPos.x - this->getCollisionRectangle().width / 2.0 < 0) {
		newPos.x = this->getCollisionRectangle().width / 2.0;
	}

	this->setPosition(newPos);
}

void LaserCannon::moveRight(double dt)
{
	Coordinate newPos = this->getPosition();
	newPos.x += this->getSpeed() * dt;

	if(newPos.x + this->getCollisionRectangle().width / 2.0 > 800) {
		newPos.x = 800 - this->getCollisionRectangle().width / 2.0;
	}

	this->setPosition(newPos);
}

}

#include <memory>

#include "LaserCannon.hpp"

#include "Bullet.hpp"

namespace Model {

LaserCannon::LaserCannon(Coordinate position, double speed, double width, double height, GlobalLoader globalConfig)
	: Entity(LASERCANNON, 3, position, speed, sf::Rect<double>(0.0, 0.0, width, height)), globalConfig(globalConfig)
{
}

LaserCannon::~LaserCannon()
{
}

void LaserCannon::onCollision(const Entity* entity)
{
	if(entity->getType() == BULLET) {
		auto bullet = static_cast<const Bullet*>(entity);

		if(bullet->getType() == Model::Bullet::FRIENDLY) {
			return;
		}

		this->doDamage(1);
		this->setPosition(Coordinate(globalConfig.getResolutionX() / 2, globalConfig.getResolutionY() - 50));
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

	if(newPos.x + this->getCollisionRectangle().width / 2.0 > globalConfig.getResolutionX()) {
		newPos.x = globalConfig.getResolutionX() - this->getCollisionRectangle().width / 2.0;
	}

	this->setPosition(newPos);
}

}

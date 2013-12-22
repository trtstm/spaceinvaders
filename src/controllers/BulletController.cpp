#include "BulletController.hpp"

BulletController::BulletController(Bullet bullet)
	: bullet(bullet)
{
}

void BulletController::update(double dt)
{
	bullet.moveUp(dt);
}

Coordinate BulletController::getPosition() const
{
	return bullet.getPosition();
}

sf::Rect<double> BulletController::getCollisionRectangle() const
{
	return bullet.getCollisionRectangle();
}

Bullet& BulletController::getBullet()
{
	return bullet;
}

bool BulletController::isAlive() const
{
	return (bullet.getHealth() > 0.0);
}

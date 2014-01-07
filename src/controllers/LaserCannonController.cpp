#include "LaserCannonController.hpp"

#include "messages/DiedMessage.hpp"
#include "messages/BulletHitMessage.hpp"

LaserCannonController::LaserCannonController(LaserCannon* laserCannon)
	: laserCannon(laserCannon)
{
}

void LaserCannonController::moveLeft(double dt)
{
	laserCannon->moveLeft(dt);
}

void LaserCannonController::moveRight(double dt)
{
	laserCannon->moveRight(dt);
}

Coordinate LaserCannonController::getPosition()
{
	return laserCannon->getPosition();
}

bool LaserCannonController::isAlive() const
{
	return (laserCannon->getHealth() > 0.0);
}

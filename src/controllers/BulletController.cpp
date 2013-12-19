#include "BulletController.hpp"

#include "components/Movable.hpp"

BulletController::BulletController(Bullet& bullet)
	: bullet(&bullet)
{
}

void BulletController::update(double dt)
{
	bullet->moveUp(dt);
}


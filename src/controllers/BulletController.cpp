#include "BulletController.hpp"

#include "components/Movable.hpp"

BulletController::BulletController(std::shared_ptr<Bullet> bullet)
	: bullet(bullet)
{
}

void BulletController::update(double dt)
{
	auto component = bullet->getComponent<Movable>();
	if(!component) {
		return;
	}

	component->moveUp(dt);
}


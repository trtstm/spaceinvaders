#include "SpaceshipController.hpp"

#include "components/Movable.hpp"

SpaceshipController::SpaceshipController(std::shared_ptr<Spaceship> spaceship)
	: spaceship(spaceship)
{
}

void SpaceshipController::moveLeft(double dt)
{
	auto movable = spaceship->getComponent<Movable>();
	if(!movable) {
		return;
	}

	movable->moveLeft(dt);
}

void SpaceshipController::moveRight(double dt)
{
	auto movable = spaceship->getComponent<Movable>();
	if(!movable) {
		return;
	}

	movable->moveRight(dt);
}

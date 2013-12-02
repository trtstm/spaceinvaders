#include "SpaceshipController.hpp"

#include "Movable.hpp"

SpaceshipController::SpaceshipController(std::shared_ptr<Spaceship> spaceship)
	: spaceship(spaceship)
{
}

void SpaceshipController::moveLeft(double dt)
{
	auto component = spaceship->getComponent<Movable>();
	if(!component) {
		return;
	}

	component->moveLeft(dt);
}

void SpaceshipController::moveRight(double dt)
{
	auto component = spaceship->getComponent<Movable>();
	if(!component) {
		return;
	}

	component->moveRight(dt);
}

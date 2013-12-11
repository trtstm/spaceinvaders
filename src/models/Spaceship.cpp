#include <memory>

#include "Spaceship.hpp"

#include "components/SpaceshipMovable.hpp"

Spaceship::Spaceship(Coordinate location, double speed)
	: Entity(std::make_shared<SpaceshipMovable>(idCounter, location, speed))
{
}

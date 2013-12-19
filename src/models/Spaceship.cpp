#include <memory>

#include "Spaceship.hpp"

#include "components/SpaceshipMovable.hpp"
#include "components/Collidable.hpp"
#include "components/Livable.hpp"

Spaceship::Spaceship(Coordinate position)
	: Entity(1, position, 400, sf::Rect<double>(0.0, 0.0, 26.0, 15.0))
{
}

Spaceship::~Spaceship()
{
}

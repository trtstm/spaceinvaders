#include "DefaultEntityFactory.hpp"

#include "models/Spaceship.hpp"

Spaceship* DefaultEntityFactory::newSpaceship(const Coordinate& position)
{
	return new Spaceship(position);
}

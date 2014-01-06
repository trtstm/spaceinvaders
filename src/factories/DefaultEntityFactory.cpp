#include "DefaultEntityFactory.hpp"

#include "models/Spaceship.hpp"
#include "models/LaserCannon.hpp"
#include "models/Alien.hpp"

Spaceship* DefaultEntityFactory::newSpaceship(const Coordinate& position)
{
	return new Spaceship(position);
}

LaserCannon* DefaultEntityFactory::newLaserCannon(const Coordinate& position)
{
	return new LaserCannon(position);
}

Alien* DefaultEntityFactory::newAlien(const Coordinate& position, double speed)
{
	return new Alien(position, speed);
}

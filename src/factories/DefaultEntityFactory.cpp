#include "DefaultEntityFactory.hpp"

namespace Factory {

Model::Spaceship* DefaultEntityFactory::newSpaceship(const Coordinate& position)
{
	return new Model::Spaceship(position);
}

Model::LaserCannon* DefaultEntityFactory::newLaserCannon(const Coordinate& position)
{
	return new Model::LaserCannon(position);
}

Model::Alien* DefaultEntityFactory::newAlien(const Coordinate& position, double speed)
{
	return new Model::Alien(position, speed);
}

}

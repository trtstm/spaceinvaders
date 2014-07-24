#include "DefaultEntityFactory.hpp"

namespace Factory {

Model::Spaceship* DefaultEntityFactory::newSpaceship(const Coordinate& position)
{
	return new Model::Spaceship(position);
}

Model::LaserCannon* DefaultEntityFactory::newLaserCannon(const Coordinate& position, GlobalLoader globalConfig)
{
	return new Model::LaserCannon(position, globalConfig);
}

Model::Alien* DefaultEntityFactory::newAlien(const Coordinate& position, double speed)
{
	return new Model::Alien(position, speed);
}

Model::Bullet* DefaultEntityFactory::newBullet(const Coordinate& position, double speed, Model::Bullet::Type type, int owner)
{
	return new Model::Bullet(position, speed, type, owner);
}

Model::BunkerLeft* DefaultEntityFactory::newBunkerLeft(const Coordinate& position)
{
	return new Model::BunkerLeft(position);
}

Model::BunkerMiddle* DefaultEntityFactory::newBunkerMiddle(const Coordinate& position)
{
	return new Model::BunkerMiddle(position);
}

Model::BunkerRight* DefaultEntityFactory::newBunkerRight(const Coordinate& position)
{
	return new Model::BunkerRight(position);
}

}

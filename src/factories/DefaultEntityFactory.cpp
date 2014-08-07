#include "DefaultEntityFactory.hpp"

namespace Factory {

Model::Spaceship* DefaultEntityFactory::newSpaceship(const Coordinate& position, GlobalLoader globalConfig)
{
	return new Model::Spaceship(position, globalConfig.get<double>("spaceship.speed"), globalConfig.get<int>("spaceship.score"),
			globalConfig.get<double>("spaceship.dimensions.x"), globalConfig.get<double>("spaceship.dimensions.y"));
}

Model::LaserCannon* DefaultEntityFactory::newLaserCannon(const Coordinate& position, GlobalLoader globalConfig)
{
	return new Model::LaserCannon(position, globalConfig.get<double>("lasercannon.speed"),
		globalConfig.get<double>("lasercannon.dimensions.x"), globalConfig.get<double>("lasercannon.dimensions.y"), globalConfig);
}

Model::Alien* DefaultEntityFactory::newAlien(const Coordinate& position, GlobalLoader globalConfig)
{
	return new Model::Alien(position, globalConfig.get<double>("invader.speed"), globalConfig.get<int>("invader.score"),
		globalConfig.get<double>("invader.dimensions.x"), globalConfig.get<double>("invader.dimensions.y"));
}

Model::Bullet* DefaultEntityFactory::newBullet(const Coordinate& position, double speed, Model::Bullet::Type type, int owner)
{
	return new Model::Bullet(position, speed, type, owner);
}

Model::BunkerLeft* DefaultEntityFactory::newBunkerLeft(const Coordinate& position, GlobalLoader globalConfig)
{
	return new Model::BunkerLeft(position, globalConfig.get<double>("bunkerleft.dimensions.x"), globalConfig.get<double>("bunkerleft.dimensions.y"));
}

Model::BunkerMiddle* DefaultEntityFactory::newBunkerMiddle(const Coordinate& position, GlobalLoader globalConfig)
{
	return new Model::BunkerMiddle(position, globalConfig.get<double>("bunkermiddle.dimensions.x"), globalConfig.get<double>("bunkermiddle.dimensions.y"));
}

Model::BunkerRight* DefaultEntityFactory::newBunkerRight(const Coordinate& position, GlobalLoader globalConfig)
{
	return new Model::BunkerRight(position, globalConfig.get<double>("bunkerright.dimensions.x"), globalConfig.get<double>("bunkerright.dimensions.y"));
}

}

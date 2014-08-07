#include "DefaultEntityFactory.hpp"

namespace Factory {

Model::Spaceship* DefaultEntityFactory::newSpaceship(const Coordinate& position, GlobalLoader globalConfig)
{
	return new Model::Spaceship(position, globalConfig.get<int>("spaceship.speed"), globalConfig.get<int>("spaceship.score"),
			globalConfig.get<int>("spaceship.dimensions.x"), globalConfig.get<int>("spaceship.dimensions.y"));
}

Model::LaserCannon* DefaultEntityFactory::newLaserCannon(const Coordinate& position, GlobalLoader globalConfig)
{
	return new Model::LaserCannon(position, globalConfig.get<int>("lasercannon.speed"),
		globalConfig.get<int>("lasercannon.dimensions.x"), globalConfig.get<int>("lasercannon.dimensions.y"), globalConfig);
}

Model::Alien* DefaultEntityFactory::newAlien(const Coordinate& position, GlobalLoader globalConfig)
{
	return new Model::Alien(position, globalConfig.get<int>("invader.speed"), globalConfig.get<int>("invader.score"),
		globalConfig.get<int>("invader.dimensions.x"), globalConfig.get<int>("invader.dimensions.y"));
}

Model::Bullet* DefaultEntityFactory::newBullet(const Coordinate& position, double speed, Model::Bullet::Type type, int owner)
{
	return new Model::Bullet(position, speed, type, owner);
}

Model::BunkerLeft* DefaultEntityFactory::newBunkerLeft(const Coordinate& position, GlobalLoader globalConfig)
{
	return new Model::BunkerLeft(position, globalConfig.get<int>("bunkerleft.dimensions.x"), globalConfig.get<int>("bunkerleft.dimensions.y"));
}

Model::BunkerMiddle* DefaultEntityFactory::newBunkerMiddle(const Coordinate& position, GlobalLoader globalConfig)
{
	return new Model::BunkerMiddle(position, globalConfig.get<int>("bunkermiddle.dimensions.x"), globalConfig.get<int>("bunkermiddle.dimensions.y"));
}

Model::BunkerRight* DefaultEntityFactory::newBunkerRight(const Coordinate& position, GlobalLoader globalConfig)
{
	return new Model::BunkerRight(position, globalConfig.get<int>("bunkerright.dimensions.x"), globalConfig.get<int>("bunkerright.dimensions.y"));
}

}

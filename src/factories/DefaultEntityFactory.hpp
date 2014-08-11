#ifndef DEFAULT_ENTITY_FACTORY_HPP
#define DEFAULT_ENTITY_FACTORY_HPP

#include "EntityFactory.hpp"

namespace Factory {

class DefaultEntityFactory : public EntityFactory {
	public:
		/**
		* See base class.
		*/
		Model::Spaceship* newSpaceship(const Coordinate& position, GlobalLoader globalConfig);

		/**
		* See base class.
		*/
		Model::LaserCannon* newLaserCannon(const Coordinate& position, GlobalLoader globalConfig);

		/**
		* See base class.
		*/
		Model::Alien* newAlien(const Coordinate& position, GlobalLoader globalConfig);

		/**
		* See base class.
		*/
		Model::Bullet* newBullet(const Coordinate& position, double speed, Model::Bullet::Type type, int owner);

		/**
		* See base class.
		*/
		Model::BunkerLeft* newBunkerLeft(const Coordinate& position, GlobalLoader globalConfig);

		/**
		* See base class.
		*/
		Model::BunkerMiddle* newBunkerMiddle(const Coordinate& position, GlobalLoader globalConfig);

		/**
		* See base class.
		*/
		Model::BunkerRight* newBunkerRight(const Coordinate& position, GlobalLoader globalConfig);
};

}

#endif

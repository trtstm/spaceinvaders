#ifndef DEFAULT_ENTITY_FACTORY_HPP
#define DEFAULT_ENTITY_FACTORY_HPP

#include "EntityFactory.hpp"

namespace Factory {

class DefaultEntityFactory : public EntityFactory {
	public:
		/**
		* Create a new spaceship.
		*
		* @param position The position.
		* @return The spaceship.
		*/
		Model::Spaceship* newSpaceship(const Coordinate& position);

		/**
		* Create a new lasercannon.
		*
		* @param position The position.
		* @return The lasercannon.
		*/
		Model::LaserCannon* newLaserCannon(const Coordinate& position);

		/**
		* Create a new alien.
		*
		* @param position The position.
		* @param position The speed.
		* @return The alien.
		*/
		Model::Alien* newAlien(const Coordinate& position, double speed);

		/**
		* Create a new bullet.
		*
		* @param position The position.
		* @param position The speed.
		* @return The alien.
		*/
		Model::Bullet* newBullet(const Coordinate& position, double speed, Model::Bullet::Type type, int owner);

		/**
		* Create a new bunker left.
		*
		* @param position The position.
		* @return The bunker left.
		*/
		Model::BunkerLeft* newBunkerLeft(const Coordinate& position);

		/**
		* Create a new bunker middle.
		*
		* @param position The position.
		* @return The bunker middle.
		*/
		Model::BunkerMiddle* newBunkerMiddle(const Coordinate& position);

		/**
		* Create a new bunker right.
		*
		* @param position The position.
		* @return The bunker right.
		*/
		Model::BunkerRight* newBunkerRight(const Coordinate& position);
};

}

#endif

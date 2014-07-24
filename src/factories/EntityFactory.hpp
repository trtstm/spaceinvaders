#ifndef ENTITY_FACTORY_HPP
#define ENTITY_FACTORY_HPP

#include "Coordinate.hpp"

#include "models/Spaceship.hpp"
#include "models/LaserCannon.hpp"
#include "models/Alien.hpp"
#include "models/Bullet.hpp"
#include "models/BunkerLeft.hpp"
#include "models/BunkerMiddle.hpp"
#include "models/BunkerRight.hpp"

#include "config/GlobalLoader.hpp"

namespace Factory {

class EntityFactory {
	public:
		virtual ~EntityFactory() {};

		/**
		* Create a new spaceship.
		*
		* @param position The position.
		* @return The spaceship.
		*/
		virtual Model::Spaceship* newSpaceship(const Coordinate& position) = 0;

		/**
		* Create a new lasercannon.
		*
		* @param position The position.
		* @return The lasercannon.
		*/
		virtual Model::LaserCannon* newLaserCannon(const Coordinate& position, GlobalLoader globalConfig) = 0;

		/**
		* Create a new alien.
		*
		* @param position The position.
		* @param position The speed.
		* @return The alien.
		*/
		virtual Model::Alien* newAlien(const Coordinate& position, double speed) = 0;

		/**
		* Create a new bullet.
		*
		* @param position The position.
		* @param position The speed.
		* @param owner The owner.
		* @return The bullet.
		*/
		virtual Model::Bullet* newBullet(const Coordinate& position, double speed, Model::Bullet::Type type, int owner) = 0;

		/**
		* Create a new bunker left.
		*
		* @param position The position.
		* @return The bunker left.
		*/
		virtual Model::BunkerLeft* newBunkerLeft(const Coordinate& position) = 0;

		/**
		* Create a new bunker middle.
		*
		* @param position The position.
		* @return The bunker middle.
		*/
		virtual Model::BunkerMiddle* newBunkerMiddle(const Coordinate& position) = 0;

		/**
		* Create a new bunker right.
		*
		* @param position The position.
		* @return The bunker right.
		*/
		virtual Model::BunkerRight* newBunkerRight(const Coordinate& position) = 0;
};

}

#endif

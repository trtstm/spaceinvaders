#ifndef ENTITY_FACTORY_HPP
#define ENTITY_FACTORY_HPP

#include "Coordinate.hpp"

#include "models/Spaceship.hpp"
#include "models/LaserCannon.hpp"
#include "models/Alien.hpp"

namespace Factory {

class EntityFactory {
	public:
		virtual ~EntityFactory() = 0;

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
		virtual Model::LaserCannon* newLaserCannon(const Coordinate& position) = 0;

		/**
		* Create a new alien.
		*
		* @param position The position.
		* @param position The speed.
		* @return The alien.
		*/
		virtual Model::Alien* newAlien(const Coordinate& position, double speed) = 0;
};

}

#endif

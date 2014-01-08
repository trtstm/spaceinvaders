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
};

}

#endif

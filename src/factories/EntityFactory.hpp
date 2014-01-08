#ifndef ENTITY_FACTORY_HPP
#define ENTITY_FACTORY_HPP

#include "Coordinate.hpp"

#include "models/Spaceship.hpp"
#include "models/LaserCannon.hpp"
#include "models/Alien.hpp"

namespace Factory {

class EntityFactory {
	public:
		virtual Model::Spaceship* newSpaceship(const Coordinate& position) = 0;
		virtual Model::LaserCannon* newLaserCannon(const Coordinate& position) = 0;
		virtual Model::Alien* newAlien(const Coordinate& position, double speed) = 0;
};

}

#endif

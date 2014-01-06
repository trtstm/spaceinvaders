#ifndef ENTITY_FACTORY_HPP
#define ENTITY_FACTORY_HPP

#include "Coordinate.hpp"

class Spaceship;
class LaserCannon;
class Alien;

class EntityFactory {
	public:
		virtual Spaceship* newSpaceship(const Coordinate& position) = 0;
		virtual LaserCannon* newLaserCannon(const Coordinate& position) = 0;
		virtual Alien* newAlien(const Coordinate& position, double speed) = 0;
};

#endif

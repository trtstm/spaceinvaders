#ifndef DEFAULT_ENTITY_FACTORY_HPP
#define DEFAULT_ENTITY_FACTORY_HPP

#include "EntityFactory.hpp"

class DefaultEntityFactory : public EntityFactory {
	public:
		Spaceship* newSpaceship(const Coordinate& position);
		LaserCannon* newLaserCannon(const Coordinate& position);
		Alien* newAlien(const Coordinate& position, double speed);
};

#endif
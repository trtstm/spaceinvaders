#ifndef DEFAULT_ENTITY_FACTORY_HPP
#define DEFAULT_ENTITY_FACTORY_HPP

#include "EntityFactory.hpp"

namespace Factory {

class DefaultEntityFactory : public EntityFactory {
	public:
		Model::Spaceship* newSpaceship(const Coordinate& position);
		Model::LaserCannon* newLaserCannon(const Coordinate& position);
		Model::Alien* newAlien(const Coordinate& position, double speed);
};

}

#endif

#ifndef ENTITY_FACTORY_HPP
#define ENTITY_FACTORY_HPP

#include "Coordinate.hpp"

class Spaceship;

class EntityFactory {
	public:
		virtual Spaceship* newSpaceship(const Coordinate& position) = 0;
};

#endif

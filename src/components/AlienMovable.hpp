#ifndef ALIEN_MOVABLE_HPP
#define ALIEN_MOVABLE_HPP

#include <memory>

#include "Movable.hpp"
#include "Coordinate.hpp"
#include "models/Entity.hpp"

class AlienMovable : public Movable {
	public:
		AlienMovable(int entity, Coordinate location);

	private:
};

#endif

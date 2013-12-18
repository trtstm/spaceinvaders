#ifndef ALIEN_MOVABLE_HPP
#define ALIEN_MOVABLE_HPP

#include <memory>

#include "Movable.hpp"
#include "Coordinate.hpp"

class AlienMovable : public Movable {
	public:
		AlienMovable(int entity, Coordinate location);

		void moveLeft(double dt);
		void moveRight(double dt);
		void moveDown(double dt);

	private:
};

#endif

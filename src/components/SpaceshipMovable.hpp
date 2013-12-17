#ifndef SPACESHIP_MOVABLE_HPP
#define SPACESHIP_MOVABLE_HPP

#include <memory>

#include "Movable.hpp"
#include "Coordinate.hpp"

class SpaceshipMovable : public Movable {
	public:
		SpaceshipMovable(int entity, Coordinate location, double speed);

		void moveLeft(double dt);
		void moveRight(double dt);
		void moveUp(double dt);
		void moveDown(double dt);

	private:
};

#endif

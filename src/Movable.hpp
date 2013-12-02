#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "Component.hpp"
#include "Coordinate.hpp"

class Movable : public Component {
	public:
		Movable();

		void moveLeft(double dt);
		void moveRight(double dt);
		void moveUp(double dt);
		void moveDown(double dt);

		void setLocation(Coordinate location);

		Coordinate getLocation() const;

	private:
		Coordinate location;
};

#endif

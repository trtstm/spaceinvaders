#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "Component.hpp"
#include "Coordinate.hpp"

class Movable : public Component {
	public:
		Movable();

		void moveLeft();
		void moveRight();
		void moveUp();
		void moveDown();

		void setLocation(Coordinate location);

		Coordinate getLocation() const;

	private:
		Coordinate location;
};

#endif

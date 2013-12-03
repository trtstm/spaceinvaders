#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include <memory>

#include "Component.hpp"
#include "Coordinate.hpp"
#include "models/Entity.hpp"

class Movable : public Component {
	public:
		Movable(std::shared_ptr<Entity> entity);
		Movable(std::shared_ptr<Entity> entity, Coordinate location, double speed);

		void moveLeft(double dt);
		void moveRight(double dt);
		void moveUp(double dt);
		void moveDown(double dt);

		void setLocation(Coordinate location);

		Coordinate getLocation() const;

	private:
		Coordinate location;
		double speed;
};

#endif

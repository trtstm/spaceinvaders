#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include <memory>

#include "Component.hpp"
#include "Coordinate.hpp"
#include "models/Entity.hpp"

class Movable : public Component {
	public:
		Movable(std::shared_ptr<Entity> entity, Coordinate location, double speed);
		virtual ~Movable();		

		virtual void moveLeft(double dt);
		virtual void moveRight(double dt);
		virtual void moveUp(double dt);
		virtual void moveDown(double dt);

		virtual void setLocation(Coordinate location);

		Coordinate getLocation() const;

	protected:
		Coordinate location;
		double speed;
};

#endif

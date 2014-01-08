#ifndef LASER_CANNON_H 
#define LASER_CANNON_H

#include "Entity.hpp"
#include "Coordinate.hpp"

namespace Model {

class LaserCannon : public Entity {
	public:
		/**
		* @param position The position.
		*/
		LaserCannon(Coordinate position = Coordinate(0, 0));
		~LaserCannon();

		/**
		* Called when another entity has collided with us.
		*
		* @param entity The entity that collided with us.
		*/
		void onCollision(const Entity* entity);

	private:
};

}

#endif

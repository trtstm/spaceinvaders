#ifndef LASER_CANNON_H 
#define LASER_CANNON_H

#include "Entity.hpp"
#include "Coordinate.hpp"

namespace Model {

class LaserCannon : public Entity {
	public:
		LaserCannon(Coordinate position = Coordinate(0, 0));
		~LaserCannon();

		void onCollision(const Entity* entity);

	private:
};

}

#endif

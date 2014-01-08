#ifndef SPACESHIP_H 
#define SPACESHIP_H

#include "Entity.hpp"
#include "Coordinate.hpp"

namespace Model {

class Spaceship : public Entity {
	public:
		Spaceship(Coordinate position = Coordinate(0, 0), double speed = 100);
		~Spaceship();

		void onCollision(const Entity* entity);

	private:
};

}

#endif

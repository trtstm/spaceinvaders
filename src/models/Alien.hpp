#ifndef ALIEN_H 
#define ALIEN_H

#include "Entity.hpp"
#include "Coordinate.hpp"

class Alien : public Entity {
	public:
		Alien(Coordinate position = Coordinate(0, 0), double speed = 16);
		~Alien();

		void moveDown(double dt);

	private:
};

#endif

#ifndef SPACESHIP_H 
#define SPACESHIP_H

#include "Entity.hpp"
#include "Coordinate.hpp"

class Spaceship : public Entity {
	public:
		Spaceship(Coordinate position = Coordinate(0, 0));
		~Spaceship();


	private:
};

#endif

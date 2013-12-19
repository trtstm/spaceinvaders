#ifndef SPACESHIP_H 
#define SPACESHIP_H

#include "Entity.hpp"
#include "Coordinate.hpp"

#include "components/SpaceshipMovable.hpp"
#include "components/Collidable.hpp"
#include "components/Livable.hpp"

class Spaceship : public Entity {
	public:
		Spaceship(Coordinate location, double speed);
		~Spaceship();

		Movable& getMovable();
		Collidable& getCollidable();
		Livable& getLivable();

	private:
		SpaceshipMovable movable;
		Collidable collidable;
		Livable livable;
};

#endif

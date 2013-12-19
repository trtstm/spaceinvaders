#ifndef ALIEN_H 
#define ALIEN_H

#include "Entity.hpp"
#include "Coordinate.hpp"

#include "components/AlienMovable.hpp"
#include "components/Collidable.hpp"
#include "components/Livable.hpp"

class Alien : public Entity {
	public:
		Alien(Coordinate location = Coordinate(0, 0));
		~Alien();

		Movable& getMovable();
		Collidable& getCollidable();
		Livable& getLivable();

	private:
		AlienMovable movable;
		Collidable collidable;
		Livable livable;
};

#endif

#ifndef BUNKER_H 
#define BUNKER_H

#include "Entity.hpp"
#include "Coordinate.hpp"

class Bunker : public Entity {
	public:
		Bunker(Coordinate position = Coordinate(0, 0));
		~Bunker();

	private:
};

#endif

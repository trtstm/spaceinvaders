#ifndef BUNKER_RIGHT_H 
#define BUNKER_RIGHT_H

#include "Entity.hpp"
#include "Coordinate.hpp"

class BunkerRight : public Entity {
	public:
		BunkerRight(Coordinate position = Coordinate(0, 0));
		~BunkerRight();

		void onCollision(const Entity* entity);

	private:
};

#endif

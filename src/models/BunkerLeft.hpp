#ifndef BUNKER_LEFT_H 
#define BUNKER_LEFT_H

#include "Entity.hpp"
#include "Coordinate.hpp"

class BunkerLeft : public Entity {
	public:
		BunkerLeft(Coordinate position = Coordinate(0, 0));
		~BunkerLeft();

		void onCollision(const Entity* entity);

	private:
};

#endif

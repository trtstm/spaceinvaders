#ifndef BUNKER_MIDDLE_H 
#define BUNKER_MIDDLE_H

#include "Entity.hpp"
#include "Coordinate.hpp"

class BunkerMiddle : public Entity {
	public:
		BunkerMiddle(Coordinate position = Coordinate(0, 0));
		~BunkerMiddle();

		void onCollision(const Entity* entity);

	private:
};

#endif

#ifndef BUNKER_LEFT_H 
#define BUNKER_LEFT_H

#include "BunkerBlock.hpp"
#include "Coordinate.hpp"

namespace Model {

class BunkerLeft : public BunkerBlock {
	public:
		BunkerLeft(Coordinate position = Coordinate(0, 0));
		~BunkerLeft();
};

}

#endif

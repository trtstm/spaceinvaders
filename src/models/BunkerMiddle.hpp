#ifndef BUNKER_MIDDLE_H 
#define BUNKER_MIDDLE_H

#include "BunkerBlock.hpp"
#include "Coordinate.hpp"

namespace Model {

class BunkerMiddle : public BunkerBlock {
	public:
		BunkerMiddle(Coordinate position = Coordinate(0, 0));
		~BunkerMiddle();
};

}

#endif

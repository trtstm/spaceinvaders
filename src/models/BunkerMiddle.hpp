#ifndef BUNKER_MIDDLE_H 
#define BUNKER_MIDDLE_H

#include "BunkerBlock.hpp"
#include "Coordinate.hpp"

namespace Model {

class BunkerMiddle : public BunkerBlock {
	public:
		/**
		* @param position The position.
		*/
		BunkerMiddle(Coordinate position, double width, double height);
		~BunkerMiddle();
};

}

#endif

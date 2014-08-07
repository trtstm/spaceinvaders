#ifndef BUNKER_LEFT_H 
#define BUNKER_LEFT_H

#include "BunkerBlock.hpp"
#include "Coordinate.hpp"

namespace Model {

class BunkerLeft : public BunkerBlock {
	public:
		/**
		* @param position The position.
		*/
		BunkerLeft(Coordinate position, double width, double height);
		~BunkerLeft();
};

}

#endif

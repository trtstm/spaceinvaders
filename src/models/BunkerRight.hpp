#ifndef BUNKER_RIGHT_HPP
#define BUNKER_RIGHT_HPP

#include "BunkerBlock.hpp"
#include "Coordinate.hpp"

namespace Model {

class BunkerRight : public BunkerBlock {
	public:
		/**
		* @param position The position.
		*/
		BunkerRight(Coordinate position = Coordinate(0, 0));
		~BunkerRight();
};

}

#endif

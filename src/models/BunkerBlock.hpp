#ifndef BUNKER_BLOCK_HPP 
#define BUNKER_BLOCK_HPP

#include "Entity.hpp"
#include "Coordinate.hpp"

namespace Model {

class BunkerBlock : public Entity {
	public:
		BunkerBlock(Coordinate position, const sf::Rect<double>& collisionRectangle);
		virtual ~BunkerBlock();

		void onCollision(const Entity* entity);
};

}

#endif

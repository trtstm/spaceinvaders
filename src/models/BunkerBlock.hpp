#ifndef BUNKER_BLOCK_HPP 
#define BUNKER_BLOCK_HPP

#include "Entity.hpp"
#include "Coordinate.hpp"

namespace Model {

class BunkerBlock : public Entity {
	public:
		/**
		* @param position The position.
		* @param collisionRectangle The collision rectangle.
		*/
		BunkerBlock(Coordinate position, const sf::Rect<double>& collisionRectangle);
		virtual ~BunkerBlock();

		/**
		* Called when another entity has collided with us.
		*
		* @param entity The entity that collided with us.
		*/
		void onCollision(const Entity* entity);
};

}

#endif

#ifndef ALIEN_H 
#define ALIEN_H

#include "Entity.hpp"
#include "Coordinate.hpp"

namespace Model {

class Alien : public Entity {
	public:
		/**
		* @param position The position.
		* @param speed The speed.
		*/
		Alien(Coordinate position = Coordinate(0, 0), double speed = 16);
		~Alien();

		/**
		* Move down.
		*
		* @param dt The delta time.
		*/
		void moveDown(double dt);

		/**
		* Called when another entity has collided with us.
		*
		* @param entity The entity that collided with us.
		*/
		void onCollision(const Entity* entity);

	private:
};

}

#endif

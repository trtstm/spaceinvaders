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
		Alien(Coordinate position, double speed, int score, double width, double height);
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

		/**
		* Called when we died.
		*
		*/
		void onDied();

	private:
		int score;
};

}

#endif

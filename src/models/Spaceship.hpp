#ifndef SPACESHIP_H 
#define SPACESHIP_H

#include "Entity.hpp"
#include "Coordinate.hpp"

namespace Model {

class Spaceship : public Entity {
	public:
		/**
		* @param position The position.
		* @param speed The speed.
		*/
		Spaceship(Coordinate position, double speed, int score, double width, double height);
		~Spaceship();

		/**
		* Called when another entity has collided with us.
		*
		* @param entity The entity that collided with us.
		*/
		void onCollision(const Entity* entity);

		/**
		* Called when we died.
		*/
		void onDied();

	private:
		int score;
};

}

#endif

#ifndef LASER_CANNON_H 
#define LASER_CANNON_H

#include "Entity.hpp"
#include "Coordinate.hpp"
#include "config/GlobalLoader.hpp"

namespace Model {

class LaserCannon : public Entity {
	public:
		/**
		* @param position The position.
		*/
		LaserCannon(Coordinate position, GlobalLoader globalConfig);
		~LaserCannon();

		/**
		* Called when another entity has collided with us.
		*
		* @param entity The entity that collided with us.
		*/
		void onCollision(const Entity* entity);

		/**
		* Move left.
		*
		* @param dt The delta time.
		*/
		void moveLeft(double dt);

		/**
		* Move right.
		*
		* @param dt The delta time.
		*/
		void moveRight(double dt);

	private:
		GlobalLoader globalConfig;
};

}

#endif

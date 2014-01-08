#ifndef BULLET_CONTROLLER_HPP
#define BULLET_CONTROLLER_HPP

#include <memory>

#include "models/Bullet.hpp"

namespace Controller {

class BulletController {
	public:
		/**
		@param bullet The bullet this controller has to control. The controller will own the pointer.
		*/
		BulletController(Model::Bullet bullet);

		/**
		* Update the alien.
		*
		* @param dt The delta time.
		*/
		void update(double dt);

		/**
		* Get the position.
		*
		* @return The position.
		*/
		Coordinate getPosition() const;

		/**
		* Get the collision rectangle.
		*
		* @return The collision rectangle.
		*/
		sf::Rect<double> getCollisionRectangle() const;

		/**
		* Checks if the bullet is alive.
		*
		* @return True if alive, else false.
		*/
		bool isAlive() const;

		/**
		* Get the bullet this controller controls.
		*
		* @return The bullet.
		*/
		Model::Bullet& getBullet();

	private:
		Model::Bullet bullet;
		
};

}

#endif

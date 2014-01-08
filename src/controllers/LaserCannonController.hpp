#ifndef LASER_CANNON_CONTROLLER_HPP
#define LASER_CANNON_CONTROLLER_HPP

#include <memory>

#include "models/LaserCannon.hpp"
#include "messages/Message.hpp"
#include "Coordinate.hpp"

namespace Controller {

class LaserCannonController {
	public:
		/**
		@param laserCannon The lasercannon this controller has to control. The controller will own the pointer.
		*/
		LaserCannonController(Model::LaserCannon* laserCannon);

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

		/**
		* Get the position.
		*
		* @return The position.
		*/
		Coordinate getPosition();

		/**
		* Checks if the lasercannon is alive.
		*
		* @return True if alive, else false.
		*/
		bool isAlive() const;

	private:
		std::shared_ptr<Model::LaserCannon> laserCannon;
		
};

}

#endif

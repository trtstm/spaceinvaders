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
		* Update the laser cannon.
		*
		* @param dt The delta time.
		*/
		void update(double dt);

	private:
		std::shared_ptr<Model::LaserCannon> laserCannon;
		
};

}

#endif

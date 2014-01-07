#ifndef LASER_CANNON_CONTROLLER_HPP
#define LASER_CANNON_CONTROLLER_HPP

#include <memory>

#include "models/LaserCannon.hpp"
#include "messages/Message.hpp"
#include "Coordinate.hpp"

class LaserCannonController {
	public:
		LaserCannonController(LaserCannon* laserCannon);

		void moveLeft(double dt);
		void moveRight(double dt);

		Coordinate getPosition();

		bool isAlive() const;

	private:
		std::shared_ptr<LaserCannon> laserCannon;
		
};

#endif

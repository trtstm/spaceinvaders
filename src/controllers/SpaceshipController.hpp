#ifndef SPACESHIP_CONTROLLER_HPP
#define SPACESHIP_CONTROLLER_HPP

#include <memory>

#include "models/Spaceship.hpp"

class SpaceshipController {
	public:
		SpaceshipController(std::shared_ptr<Spaceship> spaceship);

		void moveLeft(double dt);
		void moveRight(double dt);

	private:
		std::shared_ptr<Spaceship> spaceship;
		
};

#endif

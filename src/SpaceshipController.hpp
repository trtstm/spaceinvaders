#ifndef SPACESHIP_CONTROLLER_HPP
#define SPACESHIP_CONTROLLER_HPP

#include <memory>

#include "Spaceship.hpp"

class SpaceshipController {
	public:
		SpaceshipController(std::shared_ptr<Spaceship> spaceship);

	private:
		std::shared_ptr<Spaceship> spaceship;
		
};

#endif

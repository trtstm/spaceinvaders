#ifndef SPACESHIP_CONTROLLER_HPP
#define SPACESHIP_CONTROLLER_HPP

#include <memory>

#include "models/Spaceship.hpp"
#include "messages/Message.hpp"
#include "Coordinate.hpp"

class SpaceshipController {
	public:
		SpaceshipController(Spaceship* spaceship);

		void moveLeft(double dt);
		void moveRight(double dt);
		void moveDown(double dt);

		Coordinate getPosition();
		void setPosition(Coordinate position);

		void update(double dt);

		bool isAlive() const;

		Spaceship& getSpaceship();

	private:
		std::shared_ptr<Spaceship> spaceship;
		
};

#endif

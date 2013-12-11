#ifndef SPACESHIP_CONTROLLER_HPP
#define SPACESHIP_CONTROLLER_HPP

#include <memory>

#include "models/Spaceship.hpp"
#include "messages/Message.hpp"
#include "Observer.hpp"
#include "Coordinate.hpp"

class SpaceshipController : public Observer {
	public:
		SpaceshipController(std::shared_ptr<Spaceship> spaceship);

		void moveLeft(double dt);
		void moveRight(double dt);

		Coordinate getLocation();

		bool isAlive() const;

		bool notify(Message& msg);

	private:
		std::shared_ptr<Spaceship> spaceship;
		
};

#endif

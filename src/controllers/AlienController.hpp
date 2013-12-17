#ifndef ALIEN_CONTROLLER_HPP
#define ALIEN_CONTROLLER_HPP

#include <memory>

#include "models/Alien.hpp"
#include "messages/Message.hpp"
#include "Observer.hpp"
#include "Coordinate.hpp"

class AlienController : public Observer {
	public:
		AlienController(std::shared_ptr<Alien> alien);

		Coordinate getPosition();

		bool isAlive() const;

		bool notify(Message& msg);

	private:
		std::shared_ptr<Alien> alien;
		
};

#endif

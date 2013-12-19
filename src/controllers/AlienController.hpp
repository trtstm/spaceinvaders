#ifndef ALIEN_CONTROLLER_HPP
#define ALIEN_CONTROLLER_HPP

#include <memory>

#include "models/Alien.hpp"
#include "messages/Message.hpp"
#include "Observer.hpp"
#include "Coordinate.hpp"

enum Direction {LEFT, RIGHT, UP, DOWN};

class AlienController : public Observer {
	public:
		AlienController(Alien alien);

		void moveLeft(double dt);
		void moveRight(double dt);
		void moveDown(double dt);

		Coordinate getPosition();
		void setPosition(Coordinate position);

		Direction getDirection();
		void setDirection(Direction dir);

		void update(double dt);

		bool isAlive() const;

		Alien& getAlien();

		bool notify(Message& msg);

	private:
		Alien alien;

		Direction direction;
		
};

#endif

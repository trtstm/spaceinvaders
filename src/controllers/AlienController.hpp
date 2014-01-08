#ifndef ALIEN_CONTROLLER_HPP
#define ALIEN_CONTROLLER_HPP

#include <memory>

#include "models/Alien.hpp"
#include "messages/Message.hpp"
#include "Observer.hpp"
#include "Coordinate.hpp"

namespace Controller {

enum Direction {LEFT, RIGHT, UP, DOWN};

class AlienController {
	public:
		AlienController(Model::Alien* alien);

		void moveLeft(double dt);
		void moveRight(double dt);
		void moveDown(double dt);

		Coordinate getPosition();
		void setPosition(Coordinate position);

		Direction getDirection();
		void setDirection(Direction dir);

		void update(double dt);

		bool isAlive() const;

		Model::Alien& getAlien();

	private:
		std::shared_ptr<Model::Alien> alien;

		Direction direction;
		
};

}

#endif

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
		/**
		* @param alien The alien this controller has to control. The controller will own the pointer.
		*/
		AlienController(Model::Alien* alien);

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
		* Move down.
		*
		* @param dt The delta time.
		*/
		void moveDown(double dt);


		/**
		* Get the position.
		*
		* @return The position.
		*/
		Coordinate getPosition() const;

		/**
		* Set the position.
		*
		* @param position The position.
		*/
		void setPosition(Coordinate position);

		/**
		* Get the direction the aliens are moving.
		*
		* @return The direction.
		*/
		Direction getDirection() const;

		/**
		* Set the direction that the aliens will move to.
		*
		* @param dir The direction.
		*/
		void setDirection(Direction dir);

		/**
		* Update the alien.
		*
		* @param dt The delta time.
		*/
		void update(double dt);

		/**
		* Checks if the alien is alive.
		*
		* @return True if alive, else false.
		*/
		bool isAlive() const;

		/**
		* Get the alien this controller controls.
		*
		* @return The alien.
		*/
		Model::Alien& getAlien();

	private:
		std::shared_ptr<Model::Alien> alien;

		Direction direction;
		
};

}

#endif

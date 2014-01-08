#ifndef SPACESHIP_CONTROLLER_HPP
#define SPACESHIP_CONTROLLER_HPP

#include <memory>

#include "models/Spaceship.hpp"
#include "messages/Message.hpp"
#include "Coordinate.hpp"

namespace Controller {

class SpaceshipController {
	public:
		SpaceshipController(Model::Spaceship* spaceship);

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
		Coordinate getPosition();

		/**
		* Set the position.
		*
		* @param position The position.
		*/
		void setPosition(Coordinate position);

		/**
		* Update the alien.
		*
		* @param dt The delta time.
		*/
		void update(double dt);

		/**
		* Checks if the bullet is alive.
		*
		* @return True if alive, else false.
		*/
		bool isAlive() const;

		/**
		* Get the spaceship this controller controls.
		*
		* @return The spaceship.
		*/
		Model::Spaceship& getSpaceship();

	private:
		std::shared_ptr<Model::Spaceship> spaceship;
		
};

}

#endif

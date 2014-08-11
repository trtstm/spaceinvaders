#ifndef LASER_CANNON_CONTROLLER_HPP
#define LASER_CANNON_CONTROLLER_HPP

#include <memory>
#include <SFML/Window/Keyboard.hpp>

#include "models/LaserCannon.hpp"
#include "messages/Message.hpp"
#include "Coordinate.hpp"

class SpaceInvaders;

namespace Controller {

class LaserCannonController {
	public:
		enum Input {ARROWS, WASD};

		/**
		* @param laserCannon The lasercannon this controller has to control. The controller will own the pointer.
		* @param input What kind of input to use.
		* @param game The instance of a game. Will be used for callbacks.
		*/
		LaserCannonController(Model::LaserCannon* laserCannon, Input input, SpaceInvaders* game);

		/**
		* Update the laser cannon.
		*
		* @param dt The delta time.
		*/
		void update(double dt);

	private:
		std::shared_ptr<Model::LaserCannon> laserCannon;
		sf::Keyboard::Key left;
		sf::Keyboard::Key right;
		sf::Keyboard::Key shoot;
		SpaceInvaders* game;
		
};

}

#endif

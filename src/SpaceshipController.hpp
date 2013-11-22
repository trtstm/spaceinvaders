#ifndef SPACESHIP_CONTROLLER_HPP
#define SPACESHIP_CONTROLLER_HPP

#include "KeyboardController.hpp"

class SpaceshipController {
	public:
		/**
		* Handler for key down events.
		*
		* @param e The key event.
		*/
		void onKeyDown(const sf::Event::KeyEvent& e);

		/**
		* Handler for key up events.
		*
		* @param e The key event.
		*/
		void onKeyUp(const sf::Event::KeyEvent& e);
};

#endif

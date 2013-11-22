#ifndef KEYBOARD_CONTROLLER_HPP
#define KEYBOARD_CONTROLLER_HPP

#include <SFML/Window/Event.hpp>

class KeyboardController {
	public:
		virtual ~KeyboardController();

		/**
		* Handler for key down events.
		*
		* @param e The key event.
		*/
		virtual void onKeyDown(const sf::Event::KeyEvent& e) = 0;

		/**
		* Handler for key up events.
		*
		* @param e The key event.
		*/
		virtual void onKeyUp(const sf::Event::KeyEvent& e) = 0;
};

#endif

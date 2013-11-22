#ifndef KEYBOARD_CONTROLLER_HPP
#define KEYBOARD_CONTROLLER_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

class KeyboardController {
	public:
		virtual ~KeyboardController();

		virtual void onKeyDown(const sf::Event::KeyEvent& e) = 0;
		virtual void onKeyUp(const sf::Event::KeyEvent& e) = 0;
};

#endif

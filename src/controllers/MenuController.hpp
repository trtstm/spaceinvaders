#ifndef MENU_CONTROLLER_HPP
#define MENU_CONTROLLER_HPP

#include <vector>

#include "Subject.hpp"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>

class SpaceInvaders;

namespace Controller {

class MenuController : public Subject {
	public:
		enum Menu {NONE, MAIN, PLAY, HIGHSCORE};

		MenuController(SpaceInvaders* game);

		/**
		* Update the menu controller.
		*
		* @param dt The delta time.
		*/
		void update(double dt);

		void event(sf::Event event);

		void registerMenuSelection(Observer& observer);
		void registerMenuChange(Observer& observer);

	private:
		void down();
		void up();
		void select();

		Menu menu;
		std::vector<std::string> mainMenu;
		std::vector<std::string> playMenu;
		std::vector<std::string> highscoreMenu;

		int selection;
		
		SpaceInvaders* game;
};

}

#endif

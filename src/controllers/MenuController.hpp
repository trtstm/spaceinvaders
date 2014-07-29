#ifndef MENU_CONTROLLER_HPP
#define MENU_CONTROLLER_HPP

#include <vector>

#include "Subject.hpp"

class SpaceInvaders;

namespace Controller {

class MenuController : public Subject {
	public:
		MenuController(SpaceInvaders* game);

		/**
		* Update the menu controller.
		*
		* @param dt The delta time.
		*/
		void update(double dt);

	private:
		enum Menu {NONE, MAIN, HIGHSCORE};

		void down();
		void up();
		void select();

		Menu menu;
		std::vector<std::string> mainMenu;
		std::vector<std::string> highscoreMenu;

		int selection;
		
		SpaceInvaders* game;
};

}

#endif

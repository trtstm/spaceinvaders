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

		/**
		* @param game A game instance the menu will be part of. Will be used for callbacks.
		*/
		MenuController(SpaceInvaders* game);

		/**
		* Update the menu controller.
		*
		* @param dt The delta time.
		*/
		void update(double dt);

		/**
		* Handle an event. Used for navigating in the menu.
		*
		* @param event The event.
		*/
		void event(sf::Event event);

		/*
		* See base class.
		*/
		void registerMenuSelection(Observer& observer);

		/*
		* See base class.
		*/
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

		bool paused;
		
		SpaceInvaders* game;
};

}

#endif

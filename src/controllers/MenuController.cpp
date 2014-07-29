#include "MenuController.hpp"

#include "../SpaceInvaders.hpp"
#include "messages/MenuSelectMessage.hpp"
#include "messages/MenuChangeMessage.hpp"

#include <SFML/Window/Keyboard.hpp>
#include <iostream>

namespace Controller {

MenuController::MenuController(SpaceInvaders* game)
	: menu(NONE), mainMenu(std::vector<std::string>{"play", "highscore", "quit"}), highscoreMenu(std::vector<std::string>{"back"}), selection(0), game(game)
{
}

void MenuController::update(double dt)
{
	if(menu != NONE) {
	 	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
			down();
		} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
			up();
		} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
			select();
		} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			
		}
	} else {
	 	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			menu = MAIN;

			auto change = Message::MenuChangeMessage(mainMenu);
			notifyMenuChange(change);
			auto select = Message::MenuSelectMessage(selection);
			notifyMenuSelection(select);

			game->setState(MENU);
		}
	}
}

void MenuController::down()
{
	int wrap = 0;
	if(menu == MAIN) {
		wrap = mainMenu.size();
	} else if(menu == HIGHSCORE) {
		wrap = highscoreMenu.size();
	}

	selection += 1;
	selection = selection % wrap;

	auto select = Message::MenuSelectMessage(selection);
	notifyMenuSelection(select);

}

void MenuController::up()
{
	int wrap = 0;
	if(menu == MAIN) {
		wrap = mainMenu.size();
	} else if(menu == HIGHSCORE) {
		wrap = highscoreMenu.size();
	}

	selection -= 1;
	selection = selection % wrap;

	auto select = Message::MenuSelectMessage(selection);
	notifyMenuSelection(select);
}

void MenuController::select()
{
	if(menu == MAIN) {
		auto sel = mainMenu[selection];
		if(sel == "play") {
			game->setState(PLAYING);
		} else if(sel == "highscore") {
			menu = HIGHSCORE;
			selection = 0;
		} else if(sel == "quit") {
			menu = NONE;
			selection = 0;
			game->setState(GAMEOVER);
		}

		return;
	}
}

}

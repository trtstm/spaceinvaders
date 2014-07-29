#include "MenuController.hpp"

#include "../SpaceInvaders.hpp"
#include "messages/MenuSelectMessage.hpp"
#include "messages/MenuChangeMessage.hpp"

#include <iostream>

namespace Controller {

MenuController::MenuController(SpaceInvaders* game)
	: menu(NONE), mainMenu(std::vector<std::string>{"play", "highscore", "quit"}), highscoreMenu(std::vector<std::string>{"back"}), selection(0), game(game)
{
}

void MenuController::update(double dt)
{

}

void MenuController::event(sf::Event event)
{
	if(event.type != sf::Event::KeyPressed) {
		return;
	}

	if(menu != NONE) {
	 	if(event.key.code == sf::Keyboard::Key::Down) {
			down();
		} else if(event.key.code == sf::Keyboard::Key::Up) {
			up();
		} else if(event.key.code == sf::Keyboard::Key::Return) {
			select();
		} else if(event.key.code == sf::Keyboard::Key::Escape) {
			menu = NONE;
			game->setState(PLAYING);
		}
	} else {
	 	if(event.key.code == sf::Keyboard::Key::Escape) {
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
	if(selection < 0) {
		selection = wrap - 1;
	}

	auto select = Message::MenuSelectMessage(selection);
	notifyMenuSelection(select);
}

void MenuController::select()
{
	if(menu == MAIN) {
		auto sel = mainMenu[selection];
		if(sel == "play") {
			menu = NONE;
			selection = 0;
			game->setState(PLAYING);
		} else if(sel == "highscore") {
			menu = HIGHSCORE;
			selection = 0;

			auto change = Message::MenuChangeMessage(highscoreMenu);
			notifyMenuChange(change);
			auto select = Message::MenuSelectMessage(selection);
			notifyMenuSelection(select);
		} else if(sel == "quit") {
			menu = NONE;
			selection = 0;
			game->setState(GAMEOVER);
		}

		return;
	} else if(menu == HIGHSCORE) {
		auto sel = highscoreMenu[selection];
		if(sel == "back") {
			menu = MAIN;
			selection = 0;

			auto change = Message::MenuChangeMessage(mainMenu);
			notifyMenuChange(change);
			auto select = Message::MenuSelectMessage(selection);
			notifyMenuSelection(select);
		}

		return;
	}
}

}

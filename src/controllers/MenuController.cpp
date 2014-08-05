#include "MenuController.hpp"

#include "../SpaceInvaders.hpp"
#include "messages/MenuSelectMessage.hpp"
#include "messages/MenuChangeMessage.hpp"

#include <iostream>

namespace Controller {

MenuController::MenuController(SpaceInvaders* game)
	: menu(MAIN), mainMenu(std::vector<std::string>{"play","highscore", "quit"}), playMenu(std::vector<std::string>{"1 player", "2 players", "back"}),
	highscoreMenu(std::vector<std::string>{"back"}), selection(0), game(game)
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
			//menu = NONE;
			//game->setState(PLAYING);
		}
	} else {
	 	if(event.key.code == sf::Keyboard::Key::Escape) {
			menu = MAIN;

			auto change = Message::MenuChangeMessage(mainMenu, MAIN);
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
	} else if(menu == PLAY) {
		wrap = playMenu.size();
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
	} else if(menu == PLAY) {
		wrap = playMenu.size();
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
			menu = PLAY;
			selection = 0;
			auto change = Message::MenuChangeMessage(playMenu, PLAY);
			notifyMenuChange(change);
			auto select = Message::MenuSelectMessage(0);
			notifyMenuSelection(select);
		} else if(sel == "quit") {
			menu = NONE;
			selection = 0;
			game->setState(GAMEOVER);
		} else if(sel == "highscore") {
			menu = HIGHSCORE;
			selection = 0;
			auto change = Message::MenuChangeMessage(highscoreMenu, HIGHSCORE);
			notifyMenuChange(change);
			auto select = Message::MenuSelectMessage(0);
			notifyMenuSelection(select);
		}

		return;
	} else if(menu == PLAY) {
		auto sel = playMenu[selection];
		if(sel == "1 player") {
			game->initGame(1);
			menu = NONE;
			selection = 0;
			game->setState(PLAYING);

		} else if(sel == "2 players") {
			game->initGame(2);
			menu = NONE;
			selection = 0;
			game->setState(PLAYING);
		} else if(sel == "back") {
			auto change = Message::MenuChangeMessage(mainMenu, MAIN);
			notifyMenuChange(change);
			menu = MAIN;
			selection = 0;
			auto select = Message::MenuSelectMessage(selection);
			notifyMenuSelection(select);
		}

		return;
	} else if(menu == HIGHSCORE) {
		auto sel = highscoreMenu[selection];
		if(sel == "back") {
			auto change = Message::MenuChangeMessage(mainMenu, MAIN);
			notifyMenuChange(change);
			menu = MAIN;
			selection = 0;
			auto select = Message::MenuSelectMessage(selection);
			notifyMenuSelection(select);
		}

		return;
	}
}

void MenuController::registerMenuSelection(Observer& observer)
{
	Subject::registerMenuSelection(observer);

	auto select = Message::MenuSelectMessage(selection);
	notifyMenuSelection(select);
}

void MenuController::registerMenuChange(Observer& observer)
{
	Subject::registerMenuChange(observer);

	auto change = Message::MenuChangeMessage(mainMenu, MAIN);
	notifyMenuChange(change);
}

}

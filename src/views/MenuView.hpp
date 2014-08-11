#ifndef MENU_VIEW_HPP
#define MENU_VIEW_HPP

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include "GuiView.hpp"
#include "Observer.hpp"

#include "messages/Message.hpp"

#include "Resources.hpp"
#include "config/GlobalLoader.hpp"
#include "config/HighscoreLoader.hpp"

#include "messages/MenuChangeMessage.hpp"
#include "messages/MenuSelectMessage.hpp"

namespace View {

class MenuView : public GuiView, public Observer {
	public:
		/**
		* @param resources The resources. E.g fonts that will be used.
		* @param globalConfig The config to use. E.g for centering the text.
		* @param highscore A list of highscores to show in the menu.
		*/
		MenuView(const Resources& resources, GlobalLoader globalConfig, std::vector<Highscore> highscore);

		/**
		* See Observer base class.
		*/
		bool notify(Message::Message& msg);

		/**
		* Render the menu.
		*
		* @param w The rendering window.
		*/
		void render(sf::RenderWindow& w);

		/**
		* Update the highscores.
		*
		* @param highscore The new list of highscores.
		*/
		void setHighscores(std::vector<Highscore> highscore);

	private:
		std::vector<std::string> items;
		int selection;

		sf::Text text;
		GlobalLoader globalConfig;
		std::vector<Highscore> highscore;

		Controller::MenuController::Menu menu;
};

}

#endif

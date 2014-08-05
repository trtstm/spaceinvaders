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
		MenuView(const Resources& resources, GlobalLoader globalConfig, std::vector<Highscore> highscore);

		bool notify(Message::Message& msg);

		void render(sf::RenderWindow& w, const Resources& resources);

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

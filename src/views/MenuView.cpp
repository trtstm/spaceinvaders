#include <iostream>

#include "MenuView.hpp"

namespace View {

MenuView::MenuView(const Resources& resources, GlobalLoader globalConfig, std::vector<Highscore> highscore)
	: selection(0), globalConfig(globalConfig), highscore(highscore)
{
	text.setFont(resources.fonts.at("mono"));
	text.setCharacterSize(16);
	text.setColor(sf::Color::Red);
	text.setPosition(globalConfig.getResolutionX() / 2 - 20, 200.0);
}


bool MenuView::notify(Message::Message& msg)
{
	switch(msg.type) {
		case Message::MENU_CHANGE:
		{
			auto change = static_cast<Message::MenuChangeMessage&>(msg);
			items = change.items;
			menu = change.menu;

			break;
		}

		case Message::MENU_SELECT:
		{
			auto select = static_cast<Message::MenuSelectMessage&>(msg);
			selection = select.selection;

			break;
		}

		default:
			break;
	}

	return true;
}

void MenuView::render(sf::RenderWindow& w, const Resources& resources)
{
	(void)resources;

	std::string tmp;

	if(menu == Controller::MenuController::HIGHSCORE) {
		tmp = "highscore               players\n";

		for(auto& score : highscore) {
			std::string s = std::to_string(score.score);
			std::string p = std::to_string(score.players);
			tmp += s;
			for(int i = 0; i < 24 - s.length(); i++) {
				tmp += " ";
			}

			tmp += p + "\n";
		}

		tmp += "\n\n\n";

		for(int i = 0; i < items.size(); i++) {
			tmp += items[i];
			if(i == selection) {
				tmp += " <<";
			}
			tmp += "\n";
		}
	} else {
		for(int i = 0; i < items.size(); i++) {
			tmp += items[i];
			if(i == selection) {
				tmp += " <<";
			}
			tmp += "\n";
		}
	}

	text.setString(tmp);

	if(menu == Controller::MenuController::HIGHSCORE) {
		text.move(-115, -100);
		w.draw(text);
		text.move(115, 100);
	} else {
		w.draw(text);
	}

}

}

#include <iostream>

#include "MenuView.hpp"

namespace View {

MenuView::MenuView(const Resources& resources, GlobalLoader globalConfig)
	: selection(0), globalConfig(globalConfig)
{
	text.setFont(resources.fonts.at("default"));
	text.setCharacterSize(16);
	text.setColor(sf::Color::Red);
	text.setPosition(globalConfig.getResolutionX() / 2, 300.0);
}


bool MenuView::notify(Message::Message& msg)
{
	switch(msg.type) {
		case Message::MENU_CHANGE:
		{
			auto change = static_cast<Message::MenuChangeMessage&>(msg);
			items = change.items;

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

	for(int i = 0; i < items.size(); i++) {
		tmp += items[i];
		if(i == selection) {
			tmp += " <<";
		}
		tmp += "\n";
	}

	text.setString(tmp);

	w.draw(text);
}

}

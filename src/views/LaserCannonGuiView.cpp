#include <iostream>

#include "LaserCannonGuiView.hpp"

#include "messages/MoveMessage.hpp"
#include "messages/DiedMessage.hpp"

namespace View {

LaserCannonGuiView::LaserCannonGuiView(Coordinate position, const Resources& resources)
	: GuiView(sf::RectangleShape(sf::Vector2f(26, 15)))
{
	img.setTexture(resources.textures.at("lasercannon"));	
	img.setPosition(position.x - 26 / 2, position.y - 15 / 2);
}


bool LaserCannonGuiView::notify(Message::Message& msg)
{
	switch(msg.type) {
		case Message::MOVE:
		{
			auto moveMessage = static_cast<Message::MoveMessage&>(msg);

			auto position = moveMessage.newPosition;
			img.setPosition(position.x - 26 / 2, position.y - 15 / 2);

			break;
		}

		default:
			break;
	}

	return true;
}

void LaserCannonGuiView::render(sf::RenderWindow& w, const Resources& resources, double dt)
{
	(void)resources;
	(void)dt;

	w.draw(img);
}

}

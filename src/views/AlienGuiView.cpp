#include <iostream>

#include "AlienGuiView.hpp"

#include "components/Movable.hpp"
#include "messages/MoveMessage.hpp"

AlienGuiView::AlienGuiView(Coordinate position, const Resources& resources)
	: GuiView(sf::RectangleShape(sf::Vector2f(16, 16)))
{
	img.setTexture(resources.textures.at("invader1"));
	img.setPosition(position.x - 16 / 2, position.y - 16 / 2);
}


bool AlienGuiView::notify(Message& msg)
{
	switch(msg.type) {
		case MOVE:
		{
			auto moveMessage = static_cast<MoveMessage&>(msg);

			auto position = moveMessage.newPosition;
			img.setPosition(position.x - 16 / 2, position.y - 16 / 2);

			break;
		}		
	}
}

void AlienGuiView::render(sf::RenderWindow& w)
{
	w.draw(img);
}

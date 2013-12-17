#include <iostream>

#include "AlienGuiView.hpp"

#include "components/Movable.hpp"
#include "messages/MoveMessage.hpp"

AlienGuiView::AlienGuiView(Coordinate position)
	: GuiView(sf::RectangleShape(sf::Vector2f(50, 30)))
{
	sprite.setPosition(position.x - 50 / 2, position.y - 30 / 2);
}


bool AlienGuiView::notify(Message& msg)
{
	switch(msg.type) {
		case MOVE:
		{
			auto moveMessage = static_cast<MoveMessage&>(msg);

			auto position = moveMessage.newPosition;
			sprite.setPosition(position.x - 50 / 2, position.y - 30 / 2);

			break;
		}		
	}
}

void AlienGuiView::render(sf::RenderWindow& w)
{
	w.draw(sprite);
}

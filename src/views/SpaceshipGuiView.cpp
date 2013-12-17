#include <iostream>

#include "SpaceshipGuiView.hpp"

#include "components/Movable.hpp"
#include "messages/MoveMessage.hpp"

SpaceshipGuiView::SpaceshipGuiView(Coordinate position)
	: GuiView(sf::RectangleShape(sf::Vector2f(80, 40)))
{
	sprite.setPosition(position.x - 80 / 2, position.y - 40 / 2);
}


bool SpaceshipGuiView::notify(Message& msg)
{
	switch(msg.type) {
		case MOVE:
		{
			auto moveMessage = static_cast<MoveMessage&>(msg);

			auto position = moveMessage.newPosition;
			sprite.setPosition(position.x - 80 / 2, position.y - 40 / 2);

			break;
		}		
	}
}

void SpaceshipGuiView::render(sf::RenderWindow& w)
{
	w.draw(sprite);
}

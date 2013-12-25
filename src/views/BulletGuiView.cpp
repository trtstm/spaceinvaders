#include <iostream>

#include "BulletGuiView.hpp"

#include "messages/MoveMessage.hpp"

BulletGuiView::BulletGuiView(Coordinate position)
	: GuiView(sf::RectangleShape(sf::Vector2f(4, 10)))
{
	sprite.setPosition(position.x - 4 / 2, position.y - 10 / 2);
}


bool BulletGuiView::notify(Message& msg)
{
	switch(msg.type) {
		case MOVE:
		{
			auto moveMessage = static_cast<MoveMessage&>(msg);

			auto position = moveMessage.newPosition;
			sprite.setPosition(position.x - 4 / 2, position.y - 10 / 2);

			break;
		}

		default:
			break;
	}

	return true;
}

void BulletGuiView::render(sf::RenderWindow& w)
{
	w.draw(sprite);
}

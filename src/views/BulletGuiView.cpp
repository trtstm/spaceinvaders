#include <iostream>

#include "BulletGuiView.hpp"

#include "messages/MoveMessage.hpp"

namespace View {

BulletGuiView::BulletGuiView(Coordinate position)
	: GuiView(sf::RectangleShape(sf::Vector2f(4, 10)))
{
	sprite.setPosition(position.x - 4 / 2, position.y - 10 / 2);
}


bool BulletGuiView::notify(Message::Message& msg)
{
	switch(msg.type) {
		case Message::MOVE:
		{
			auto moveMessage = static_cast<Message::MoveMessage&>(msg);

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

}

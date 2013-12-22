#include <iostream>

#include "SpaceshipGuiView.hpp"

#include "messages/MoveMessage.hpp"
#include "messages/DiedMessage.hpp"

SpaceshipGuiView::SpaceshipGuiView(Coordinate position, const Resources& resources)
	: GuiView(sf::RectangleShape(sf::Vector2f(48, 21)))
{
	img.setTexture(resources.textures.at("spaceship"));
	img.setPosition(position.x - 48 / 2, position.y - 21 / 2);
}


bool SpaceshipGuiView::notify(Message& msg)
{
	switch(msg.type) {
		case MOVE:
		{
			auto moveMessage = static_cast<MoveMessage&>(msg);

			auto position = moveMessage.newPosition;
			img.setPosition(position.x - 48 / 2, position.y - 21 / 2);

			break;
		}
	}

	return true;
}

void SpaceshipGuiView::render(sf::RenderWindow& w, const Resources& resources)
{
	w.draw(img);
}

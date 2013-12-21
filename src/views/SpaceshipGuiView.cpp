#include <iostream>

#include "SpaceshipGuiView.hpp"

#include "components/Movable.hpp"
#include "messages/MoveMessage.hpp"

SpaceshipGuiView::SpaceshipGuiView(Coordinate position, const Resources& resources)
	: GuiView(sf::RectangleShape(sf::Vector2f(26, 15)))
{
	img.setTexture(resources.textures.at("lasercannon"));	
	img.setPosition(position.x - 26 / 2, position.y - 15 / 2);
}


bool SpaceshipGuiView::notify(Message& msg)
{
	switch(msg.type) {
		case MOVE:
		{
			auto moveMessage = static_cast<MoveMessage&>(msg);

			auto position = moveMessage.newPosition;
			img.setPosition(position.x - 26 / 2, position.y - 15 / 2);

			break;
		}		
	}
}

void SpaceshipGuiView::render(sf::RenderWindow& w, const Resources& resources, double dt)
{
	w.draw(img);
}

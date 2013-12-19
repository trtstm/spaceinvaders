#include <iostream>

#include "AlienGuiView.hpp"

#include "components/Movable.hpp"
#include "messages/MoveMessage.hpp"

AlienGuiView::AlienGuiView(Coordinate position)
	: GuiView(sf::RectangleShape(sf::Vector2f(16, 16))), timer(0.0), curTexture("invader1")
{
	//img.setTexture(resources.textures.at(curTexture));
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

void AlienGuiView::render(sf::RenderWindow& w, const Resources& resources, double dt)
{
	if(timer == 0.0) {
		if(curTexture == "invader1") {
			curTexture = "invader2";

			img.setTexture(resources.textures.at(curTexture));
		} else {
			curTexture = "invader1";

			img.setTexture(resources.textures.at(curTexture));
		}

		if(timer >= 1.0) {
			timer = 0.0;
		}
	}

	w.draw(img);

	timer += dt;
}

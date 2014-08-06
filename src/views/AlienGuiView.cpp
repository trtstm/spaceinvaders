#include <iostream>

#include "AlienGuiView.hpp"

#include "messages/MoveMessage.hpp"
#include "messages/DiedMessage.hpp"

namespace View {

AlienGuiView::AlienGuiView(Coordinate position, const Resources& resources)
	: GuiView(sf::RectangleShape(sf::Vector2f(16, 16))), curTexture("invader1"), timer(0.0)
{
	img.setTexture(resources.textures.at(curTexture));
	img.setPosition(position.x - 16 / 2, position.y - 16 / 2);
}


bool AlienGuiView::notify(Message::Message& msg)
{
	switch(msg.type) {
		case Message::MOVE:
		{
			auto moveMessage = static_cast<Message::MoveMessage&>(msg);

			auto position = moveMessage.newPosition;
			img.setPosition(position.x - 16 / 2, position.y - 16 / 2);

			break;
		}

		case Message::DIED:
		{
			curTexture = "explosion1";
		}

		default:
			break;
	}

	return true;
}

void AlienGuiView::render(sf::RenderWindow& w, const Resources& resources, double dt)
{
	if(curTexture == "") {
		return;
	}

	if(timer >= 1.0 && curTexture != "explosion1") {
		if(curTexture == "invader1") {
			curTexture = "invader2";
		} else {
			curTexture = "invader1";
		}

		img.setTexture(resources.textures.at(curTexture));
		timer = 0.0;
	}

	if(curTexture == "explosion1") {
		img.setTexture(resources.textures.at(curTexture));
		curTexture = "";
	}

	w.draw(img);

	timer += dt;
}

}

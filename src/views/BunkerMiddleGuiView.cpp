#include <iostream>

#include "BunkerMiddleGuiView.hpp"

#include "messages/BulletHitMessage.hpp"
#include "messages/DiedMessage.hpp"

namespace View {

BunkerMiddleGuiView::BunkerMiddleGuiView(Coordinate position, const Resources& resources)
	: GuiView(sf::RectangleShape(sf::Vector2f(16, 16))),
		img1(resources.textures.at("bunkermiddle1")),
		img2(resources.textures.at("bunkermiddle2")),
		img3(resources.textures.at("bunkermiddle3")),
		curImage(1),
		timer(0.0)
{
	img1.setPosition(position.x - 22 / 2, position.y - 28 / 2);
	img2.setPosition(position.x - 22 / 2, position.y - 28 / 2);
	img3.setPosition(position.x - 22 / 2, position.y - 28 / 2);
}


bool BunkerMiddleGuiView::notify(Message::Message& msg)
{
	switch(msg.type) {
		case Message::BULLETHIT:
		{
			curImage += 1;
		}

		default:
			break;
	}

	return true;
}

void BunkerMiddleGuiView::render(sf::RenderWindow& w, const Resources& resources, double dt)
{
	(void)dt;
	(void)resources;

	if(curImage == 1) {
		w.draw(img1);
	}
	else if(curImage == 2) {
		w.draw(img2);
	}
	else if(curImage == 3) {
		w.draw(img3);
	}
}

}

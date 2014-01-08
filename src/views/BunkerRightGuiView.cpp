#include <iostream>

#include "BunkerRightGuiView.hpp"

#include "messages/BulletHitMessage.hpp"
#include "messages/DiedMessage.hpp"

namespace View {

BunkerRightGuiView::BunkerRightGuiView(Coordinate position, const Resources& resources)
	: GuiView(sf::RectangleShape(sf::Vector2f(16, 16))),
		img1(resources.textures.at("bunkerright1")),
		img2(resources.textures.at("bunkerright2")),
		img3(resources.textures.at("bunkerright3")),
		curImage(1),
		timer(0.0)
{
	img1.setPosition(position.x - 10 / 2, position.y - 32 / 2);
	img2.setPosition(position.x - 10 / 2, position.y - 32 / 2);
	img3.setPosition(position.x - 10 / 2, position.y - 32 / 2);
}


bool BunkerRightGuiView::notify(Message::Message& msg)
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

void BunkerRightGuiView::render(sf::RenderWindow& w, const Resources& resources, double dt)
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

#include <iostream>

#include "BunkerGuiView.hpp"

#include "messages/BulletHitMessage.hpp"
#include "messages/DiedMessage.hpp"

BunkerGuiView::BunkerGuiView(Coordinate position)
	: GuiView(sf::RectangleShape(sf::Vector2f(16, 16))),
		sprite1(ImgInfo{"blockleft", sf::Sprite()}),
		sprite2(ImgInfo{"blockmiddle", sf::Sprite()}),
		sprite3(ImgInfo{"blockright", sf::Sprite()}),
		timer(0.0)
{
	sprite1.img.setPosition(position.x - 22 / 2 - 10, position.y - 32 / 2);
	sprite2.img.setPosition(position.x - 22 / 2, position.y - 32 / 2);
	sprite3.img.setPosition(position.x + 22 / 2, position.y - 32 / 2);

	//img.setTexture(resources.textures.at(curTexture));
	//img.setPosition(position.x - 10 / 2, position.y - 32 / 2);
}


bool BunkerGuiView::notify(Message& msg)
{
	switch(msg.type) {
		case BULLETHIT:
		{
		}

		default:
			break;
	}

	return true;
}

void BunkerGuiView::render(sf::RenderWindow& w, const Resources& resources, double dt)
{
	(void)dt;

	sprite1.img.setTexture(resources.textures.at(sprite1.texture));
	sprite2.img.setTexture(resources.textures.at(sprite2.texture));
	sprite3.img.setTexture(resources.textures.at(sprite3.texture));
	//img.setTexture(resources.textures.at(curTexture));
	w.draw(sprite1.img);
	w.draw(sprite2.img);
	w.draw(sprite3.img);
}

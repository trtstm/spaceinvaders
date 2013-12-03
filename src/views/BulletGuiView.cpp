#include <iostream>

#include "BulletGuiView.hpp"

#include "components/Movable.hpp"
#include "messages/MoveMessage.hpp"

BulletGuiView::BulletGuiView(std::shared_ptr<Bullet> bullet)
	: bullet(bullet)
{
}


bool BulletGuiView::notify(Message& msg)
{
	return true;
}

void BulletGuiView::render(sf::RenderWindow& w)
{
	auto movable = bullet->getComponent<Movable>();
	if(!movable) {
		return;
	}

	sf::RectangleShape rectangle(sf::Vector2f(10, 20));

	Coordinate location = movable->getLocation();

	rectangle.setPosition(location.x - 10 / 2, location.y - 10 / 2);

	w.draw(rectangle);
}
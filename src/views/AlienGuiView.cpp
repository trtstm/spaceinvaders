#include <iostream>

#include "AlienGuiView.hpp"

#include "components/Movable.hpp"
#include "messages/MoveMessage.hpp"

AlienGuiView::AlienGuiView(std::shared_ptr<Alien> alien)
	: alien(alien)
{
}


bool AlienGuiView::notify(Message& msg)
{
	return true;
}

void AlienGuiView::render(sf::RenderWindow& w)
{
	auto movable = alien->getMovable();

	sf::RectangleShape rectangle(sf::Vector2f(50, 30));

	Coordinate location = movable.getLocation();

	rectangle.setPosition(location.x - 50 / 2, location.y - 30 / 2);

	w.draw(rectangle);
}

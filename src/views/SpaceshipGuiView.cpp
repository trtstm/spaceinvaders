#include <iostream>

#include "SpaceshipGuiView.hpp"

#include "components/Movable.hpp"
#include "messages/MoveMessage.hpp"

SpaceshipGuiView::SpaceshipGuiView(std::shared_ptr<Spaceship> spaceship)
	: spaceship(spaceship)
{
}


bool SpaceshipGuiView::notify(Message& msg)
{
	return true;
}

void SpaceshipGuiView::render(sf::RenderWindow& w)
{
	auto& movable = spaceship->getMovable();

	sf::RectangleShape rectangle(sf::Vector2f(80, 40));

	Coordinate location = movable.getLocation();

	rectangle.setPosition(location.x - 80 / 2, location.y - 40 / 2);

	w.draw(rectangle);
}

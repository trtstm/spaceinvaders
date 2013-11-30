#include <iostream>

#include "SpaceshipGuiView.hpp"

#include "Movable.hpp"
#include "MoveMessage.hpp"

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
	sf::RectangleShape rectangle(sf::Vector2f(120, 50));

	Coordinate location = spaceship->getComponent<Movable>()->getLocation();

	rectangle.setPosition(location.x, location.y);

	w.draw(rectangle);
}

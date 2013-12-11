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
	auto movable = spaceship->getComponent<Movable>();

	sf::RectangleShape rectangle(sf::Vector2f(120, 50));

	Coordinate location = movable->getLocation();

	rectangle.setPosition(location.x - 120 / 2, location.y - 50 / 2);

	w.draw(rectangle);
}

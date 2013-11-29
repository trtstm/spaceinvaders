#include <SFML/Window.hpp>
#include <iostream>
#include <memory>

#include "SpaceshipController.hpp"
#include "Entity.hpp"
#include "Spaceship.hpp"
#include "Movable.hpp"
#include "SpaceshipTextView.hpp"

int main()
{
	auto spaceship = std::make_shared<Spaceship>();
	auto view = std::make_shared<SpaceshipTextView>();
	auto movable = std::make_shared<Movable>();
	movable->registerObserver(view);
	spaceship->setComponent(movable);

	SpaceshipController spc(spaceship);
	spaceship->getComponent<Movable>()->moveLeft();

    // run the program as long as the window is open

    return 0;
}

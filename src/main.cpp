#include <SFML/Window.hpp>
#include <iostream>
#include <memory>

#include "SpaceshipController.hpp"
#include "Entity.hpp"
#include "Spaceship.hpp"
#include "Movable.hpp"

int main()
{
	auto spaceship = std::make_shared<Spaceship>();
	spaceship->setComponent(std::make_shared<Movable>());

	SpaceshipController spc(spaceship);

    // run the program as long as the window is open

    return 0;
}

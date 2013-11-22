#include <SFML/Window.hpp>
#include <iostream>

#include "KeyboardController.hpp"
#include "Entity.hpp"
#include "Movable.hpp"

int main()
{
	Entity entity;
	entity.setComponent("movable", new Movable);
	std::cout << entity.getComponent<Movable>("movable")->getLocation().x << std::endl;

    sf::Window window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
		{
			if(event.type == sf::Event::KeyPressed) {
				std::cout << "PRESS" << std::endl;
			}

            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

		window.display();
    }

    return 0;
}

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <memory>
#include <array>

#include "SpaceshipController.hpp"
#include "Entity.hpp"
#include "Spaceship.hpp"
#include "Movable.hpp"
#include "SpaceshipTextView.hpp"
#include "SpaceshipGuiView.hpp"

int main()
{
	auto spaceship = std::make_shared<Spaceship>();
	auto view = std::make_shared<SpaceshipGuiView>(spaceship);
	auto movable = std::make_shared<Movable>();
	movable->setLocation(Coordinate(400,575));
	movable->registerObserver(view);
	spaceship->setComponent(movable);

	SpaceshipController spc(spaceship);

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

	std::array<bool, sf::Keyboard::KeyCount> keys;
	keys.fill(false);

	sf::Clock clock;
	while(window.isOpen()) {
		sf::Event event;
        while(window.pollEvent(event)) {
			switch(event.type) {
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyPressed:
				{
					keys[event.key.code] = true;
					break;
				}

				case sf::Event::KeyReleased:
				{
					keys[event.key.code] = false;
					break;
				}

				default:
					break;
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}

		double dt = clock.restart().asSeconds();

		if(keys[sf::Keyboard::Left]) {
			spc.moveLeft(dt);
		}

		if(keys[sf::Keyboard::Right]) {
			spc.moveRight(dt);
		}

		window.clear(sf::Color::Black);

		view->render(window);

		window.display();
	}

    return 0;
}

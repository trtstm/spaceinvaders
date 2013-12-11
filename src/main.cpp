#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <memory>
#include <array>

#include "SpaceInvaders.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Spaceinvaders");

	SpaceInvaders game;

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
					if(event.key.code == sf::Keyboard::Escape) {
						window.close();
						break;
					}

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
		}

		double dt = clock.restart().asSeconds();

		if(keys[sf::Keyboard::Left]) {
			game.moveLeft(dt);
		}

		if(keys[sf::Keyboard::Right]) {
			game.moveRight(dt);
		}

		if(keys[sf::Keyboard::Space]) {
			keys[sf::Keyboard::Space] = false;
			game.shoot();
		}

		game.update(dt);

		window.clear(sf::Color::Black);

		game.render(window);

		window.display();
	}

    return 0;
}

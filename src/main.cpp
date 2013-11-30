#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <memory>

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
	movable->registerObserver(view);
	spaceship->setComponent(movable);

	SpaceshipController spc(spaceship);

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

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
					}
					else if(event.key.code == sf::Keyboard::Left) {
						spaceship->getComponent<Movable>()->moveLeft();
					}
					else if(event.key.code == sf::Keyboard::Right) {
						spaceship->getComponent<Movable>()->moveRight();
					}
					else if(event.key.code == sf::Keyboard::Up) {
						spaceship->getComponent<Movable>()->moveUp();
					}
					else if(event.key.code == sf::Keyboard::Down) {
						spaceship->getComponent<Movable>()->moveDown();
					}

					break;
				}

				default:

					break;
			}

			if (event.type == sf::Event::Closed)
				window.close();
			}


			sf::Time dt = clock.restart();

			window.clear(sf::Color::Black);

			view->render(window);

			window.display();
	}

    return 0;
}

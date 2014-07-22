#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <string>
#include <memory>
#include <array>

#include "SpaceInvaders.hpp"
#include "config/GlobalLoader.hpp"
#include "exceptions/FileException.hpp"
#include "helpers.hpp"

int main()
{
	GlobalLoader globalConfig;
	globalConfig.load("../resources/config/config.json");

    sf::RenderWindow window(sf::VideoMode(globalConfig.getResolutionX(), globalConfig.getResolutionY()), "Spaceinvaders");
	window.setFramerateLimit(globalConfig.getFps());

	try {
		SpaceInvaders game(globalConfig);

		std::array<bool, sf::Keyboard::KeyCount> keys;
		keys.fill(false);

		sf::Font font;
		if(!font.loadFromFile("../resources/DejaVuSans.ttf")) {
			throw FileException("DejaVuSans.ttf");
		}

		sf::Text text;
		text.setFont(font);
		text.setCharacterSize(16);
		text.setColor(sf::Color::Red);
		text.setPosition(10.0, 10.0);

		sf::Clock clock;
		while(window.isOpen() && !game.shouldStop()) {
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

			game.update(dt);

			window.clear(sf::Color::Black);

			game.render(window, dt);

			text.setString(("Fps: " + toString(1.0/dt)).c_str());
			window.draw(text);

			window.display();
		}
	}
	catch (FileException& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
    return 0;
}

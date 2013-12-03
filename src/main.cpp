#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <memory>
#include <array>

#include "controllers/SpaceshipController.hpp"
#include "controllers/BulletController.hpp"
#include "models/Entity.hpp"
#include "models/Spaceship.hpp"
#include "models/Bullet.hpp"
#include "components/Movable.hpp"
#include "views/SpaceshipTextView.hpp"
#include "views/SpaceshipGuiView.hpp"
#include "views/BulletGuiView.hpp"

int main()
{
	auto spaceship = std::make_shared<Spaceship>();
	auto spaceshipMovable = std::make_shared<Movable>(Coordinate(400,575), 800);
	auto spaceshipView = std::make_shared<SpaceshipGuiView>(spaceship);
	spaceshipMovable->registerObserver(spaceshipView);
	spaceship->setComponent(spaceshipMovable);
	SpaceshipController spaceshipController(spaceship);

	auto bullet = std::make_shared<Bullet>();
	auto bulletMovable = std::make_shared<Movable>(Coordinate(400,575), 100);
	auto bulletView = std::make_shared<BulletGuiView>(bullet);
	bulletMovable->registerObserver(bulletView);
	bullet->setComponent(bulletMovable);
	BulletController bulletController(bullet);

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
		}

		double dt = clock.restart().asSeconds();

		if(keys[sf::Keyboard::Left]) {
			spaceshipController.moveLeft(dt);
		}

		if(keys[sf::Keyboard::Right]) {
			spaceshipController.moveRight(dt);
		}

		bulletController.update(dt);

		window.clear(sf::Color::Black);

		spaceshipView->render(window);
		bulletView->render(window);

		window.display();
	}

    return 0;
}

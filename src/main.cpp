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
#include "components/SpaceshipMovable.hpp"
#include "components/Collidable.hpp"
#include "views/SpaceshipTextView.hpp"
#include "views/SpaceshipGuiView.hpp"
#include "views/BulletGuiView.hpp"
#include "systems/CollisionSystem.hpp"

int main()
{
	auto block = std::make_shared<Spaceship>();
	auto blockMovable = std::make_shared<Movable>(block, Coordinate(400,200), 800);
	auto blockCollidable = std::make_shared<Collidable>(block);
	auto blockView = std::make_shared<SpaceshipGuiView>(block);
	blockMovable->registerObserver(blockView);
	block->setComponent(blockMovable);
	block->setComponent(blockCollidable);

	auto spaceship = std::make_shared<Spaceship>();
	auto spaceshipMovable = std::make_shared<SpaceshipMovable>(spaceship, Coordinate(400,575), 800);
	auto spaceshipCollidable = std::make_shared<Collidable>(spaceship);
	auto spaceshipView = std::make_shared<SpaceshipGuiView>(spaceship);
	spaceshipMovable->registerObserver(spaceshipView);
	spaceship->setComponent<Movable>(spaceshipMovable);
	spaceship->setComponent(spaceshipCollidable);
	SpaceshipController spaceshipController(spaceship);

	auto bullet = std::make_shared<Bullet>();
	auto bulletMovable = std::make_shared<Movable>(bullet, Coordinate(400,575), 100);
	auto bulletCollidable = std::make_shared<Collidable>(bullet);
	auto bulletView = std::make_shared<BulletGuiView>(bullet);
	bulletMovable->registerObserver(bulletView);
	bullet->setComponent(bulletMovable);
	bullet->setComponent(bulletCollidable);
	BulletController bulletController(bullet);

	auto collisions = std::make_shared<CollisionSystem>();

	bulletMovable->registerObserver(collisions);
	collisions->addEntity(spaceship);
	collisions->addEntity(bullet);

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

		blockView->render(window);
		spaceshipView->render(window);
		bulletView->render(window);

		window.display();
	}

    return 0;
}

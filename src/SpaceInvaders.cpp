#include "SpaceInvaders.hpp"

#include "systems/CollisionSystem.hpp"
#include "Coordinate.hpp"

#include "components/Collidable.hpp"
#include "components/Livable.hpp"

SpaceInvaders::SpaceInvaders()
	:
		timer(0.0),
		spaceship(Coordinate(400,580), 400),
		spaceshipController(spaceship),
		spaceshipView(spaceship.getMovable().getPosition())
{
	resources.textures["lasercannon"] = sf::Texture();
	resources.textures["invader1"] = sf::Texture();

	if(!resources.textures["lasercannon"].loadFromFile("../resources/lasercannon.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!resources.textures["invader1"].loadFromFile("../resources/invader1.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!resources.textures["invader2"].loadFromFile("../resources/invader2.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	spaceship.getMovable().registerObserver(spaceshipView);

	collisions.addEntity(spaceship);


	for(unsigned int y = 0; y < 5; y++) {
		for(unsigned int i = 0; i < 11; i++) {
			auto position = Coordinate(235 + i * 30, 50 + y * 30);
			auto alien = Alien(position);
			auto alienController = AlienController(alien);
			auto alienView = AlienGuiView(position);
			alien.getMovable().registerObserver(alienView);

			AlienInfo alienInfo{alien, alienController, alienView};


			aliens.push_back(alienInfo);
			collisions.addEntity(alien);
		}
	}
}

SpaceInvaders::~SpaceInvaders()
{
	spaceship.unRegisterObservers();

	for(auto& alienInfo : aliens) {
		alienInfo.model.unRegisterObservers();
	}

	for(auto& bulletInfo : bullets) {
		bulletInfo.model.unRegisterObservers();
	}
}

void SpaceInvaders::update(double dt)
{
	for(auto bulletInfo = bullets.begin(); bulletInfo != bullets.end();) {
		bulletInfo->controller.update(dt);

	}/*

	if(timer >= 1.0) {
		bool goDown = false;
		for(auto& alienInfo : aliens) {
			auto oldPosition = alienInfo.controller.getPosition();
			alienInfo.controller.update(1.0);
			auto newPosition = alienInfo.controller.getPosition();

			auto direction = alienInfo.controller.getDirection();

			if(direction == LEFT && newPosition.x - 16/2 <= 0) {
				goDown = true;
			}
			else if(direction == RIGHT && newPosition.x + 16/2 >= 800) {
				goDown = true;
			}

			alienInfo.controller.setPosition(oldPosition);
		}

		for(auto& alienInfo : aliens) {
			if(goDown) {
				alienInfo.controller.moveDown(1.0);

				auto direction = alienInfo.controller.getDirection();
				if(direction == LEFT) {
					alienInfo.controller.setDirection(RIGHT);
				} else if(direction == RIGHT) {
					alienInfo.controller.setDirection(LEFT);
				}
			} else {
				alienInfo.controller.update(1.0);
			}
		}

		if(!spaceshipController.isAlive()) {
			std::cout << "We died" << std::endl;
		}

		timer = 0.0;
	}

	timer += dt;*/
}

void SpaceInvaders::render(sf::RenderWindow& window, double dt)
{
	spaceshipView.render(window, resources, dt);

	for(auto& bulletInfo : bullets) {
		bulletInfo.view.render(window);
	}

	for(auto& alienInfo : aliens) {
		alienInfo.view.render(window, resources, dt);
	}
}

void SpaceInvaders::moveLeft(double dt)
{
	spaceshipController.moveLeft(dt);
}

void SpaceInvaders::moveRight(double dt)
{
	spaceshipController.moveRight(dt);
}

void SpaceInvaders::shoot()
{
	auto bulletPosition = spaceshipController.getPosition();

	auto bullet = Bullet(bulletPosition, 300, spaceship.getId());
	auto bulletController = BulletController(bullet);
	auto bulletView = BulletGuiView(bulletPosition);

	BulletInfo info{bullet, bulletController, bulletView};

	bullets.push_back(info);

	bullets.back().model.getCollidable().registerObserver(spaceshipController);
	bullets.back().model.getMovable().registerObserver(bullets.back().view);
	bullets.back().model.getMovable().registerObserver(collisions);

	for(auto& alienInfo : aliens) {
		bullets.back().model.getCollidable().registerObserver(alienInfo.controller);
	}

	collisions.addEntity(bullets.back().model);

}

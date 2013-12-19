#include "SpaceInvaders.hpp"

#include "systems/CollisionSystem.hpp"
#include "Coordinate.hpp"

#include "components/Collidable.hpp"
#include "components/Livable.hpp"

SpaceInvaders::SpaceInvaders()
	:
		timer(0.0),
		spaceship(Coordinate(400,580)),
		spaceshipController(spaceship),
		spaceshipView(spaceship.getPosition())
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

	spaceship.registerObserver(spaceshipView);

	collisions.addEntity(spaceship);


	for(unsigned int y = 0; y < 5; y++) {
		for(unsigned int i = 0; i < 11; i++) {
			auto position = Coordinate(235 + i * 30, 50 + y * 30);
			auto alien = Alien(position);
			auto alienController = AlienController(alien);
			auto alienView = AlienGuiView(position);

			AlienInfo alienInfo{alienController, alienView};
			aliens.push_back(alienInfo);

			aliens.back().controller.getAlien().registerObserver(alienView);
			collisions.addEntity(aliens.back().controller.getAlien());
		}
	}

}

SpaceInvaders::~SpaceInvaders()
{
	spaceship.unRegisterObservers();
	collisions.removeEntity(spaceship.getId());

	for(auto& alienInfo : aliens) {
		alienInfo.controller.getAlien().unRegisterObservers();
	}

	for(auto& bulletInfo : bullets) {
		bulletInfo->controller.getBullet().unRegisterObservers();
	}
}

void SpaceInvaders::update(double dt)
{

	for(auto bulletInfo = bullets.begin(); bulletInfo != bullets.end();) {
		(*bulletInfo)->controller.update(dt);

		auto position = (*bulletInfo)->controller.getPosition();
		auto rect = (*bulletInfo)->controller.getCollisionRectangle();

		if(position.y - rect.height / 2 < 0) {
			collisions.removeEntity((*bulletInfo)->controller.getBullet().getId());

			bulletInfo = bullets.erase(bulletInfo);
		} else {
			bulletInfo++;
		}
	}

/*
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
		bulletInfo->view.render(window);
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

	auto bulletController = BulletController(Bullet(bulletPosition, spaceship.getId()));
	auto bulletView = BulletGuiView(bulletPosition);

	std::unique_ptr<BulletInfo> info(new BulletInfo{bulletController, bulletView});
	bullets.push_back(std::move(info));

	bullets.back()->controller.getBullet().registerObserver(bullets.back()->view);

	//bullets.back().controller.getBullet().registerObserver(spaceshipController);

	//bullets.back()->controller.getBullet().registerObserver(collisions);

	for(auto& alienInfo : aliens) {
		bullets.back()->controller.getBullet().registerObserver(alienInfo.controller);
	}

	collisions.addEntity(bullets.back()->controller.getBullet());

}

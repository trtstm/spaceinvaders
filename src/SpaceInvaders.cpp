#include "SpaceInvaders.hpp"

#include "systems/CollisionSystem.hpp"
#include "Coordinate.hpp"

#include "models/Spaceship.hpp"
#include "views/SpaceshipGuiView.hpp"
#include "controllers/SpaceshipController.hpp"
#include "components/SpaceshipMovable.hpp"

#include "models/Alien.hpp"
#include "views/AlienGuiView.hpp"
#include "controllers/AlienController.hpp"
#include "components/AlienMovable.hpp"

#include "models/Bullet.hpp"
#include "views/BulletGuiView.hpp"
#include "controllers/BulletController.hpp"
#include "components/BulletCollidable.hpp"


#include "components/Collidable.hpp"
#include "components/Livable.hpp"

SpaceInvaders::SpaceInvaders()
	: collisions(std::make_shared<CollisionSystem>()), timer(0.0)
{
	resources.textures["lasercannon"] = sf::Texture();
	resources.textures["invader1"] = sf::Texture();

	if(!resources.textures["lasercannon"].loadFromFile("../resources/lasercannon.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!resources.textures["invader1"].loadFromFile("../resources/invader1.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	spaceship = std::make_shared<Spaceship>(Coordinate(400,580), 400);
	spaceshipController = std::make_shared<SpaceshipController>(spaceship);
	spaceshipView = std::make_shared<SpaceshipGuiView>(spaceship->getMovable().getPosition(), resources);
	spaceship->getMovable().registerObserver(spaceshipView);

	collisions->addEntity(spaceship);


	for(unsigned int y = 0; y < 5; y++) {
		for(unsigned int i = 0; i < 11; i++) {
			auto position = Coordinate(235 + i * 30, 50 + y * 30);
			auto alien = std::make_shared<Alien>(position);
			auto alienController = std::make_shared<AlienController>(alien);
			auto alienView = std::make_shared<AlienGuiView>(position, resources);
			alien->getMovable().registerObserver(alienView);

			AlienInfo alienInfo;
			alienInfo.model = alien;
			alienInfo.view = alienView;
			alienInfo.controller = alienController;

			aliens.push_back(alienInfo);
			collisions->addEntity(alien);
		}
	}
}

SpaceInvaders::~SpaceInvaders()
{
	spaceship->unRegisterObservers();

	for(auto& alienInfo : aliens) {
		alienInfo.model->unRegisterObservers();
	}

	for(auto& bulletInfo : bullets) {
		bulletInfo.model->unRegisterObservers();
	}
}

void SpaceInvaders::update(double dt)
{
	for(auto bulletInfo = bullets.begin(); bulletInfo != bullets.end();) {
		bulletInfo->controller->update(dt);

		if(bulletInfo->model->getMovable().getPosition().y < -50 || bulletInfo->model->getMovable().getPosition().y > 650 || bulletInfo->model->getCollidable().hasCollided()) {
			collisions->removeEntity(bulletInfo->model->getId());
			bulletInfo = bullets.erase(bulletInfo);
		} else {
			bulletInfo++;
		}
	}

	for(auto alienInfo = aliens.begin(); alienInfo != aliens.end();) {
		if(!alienInfo->controller->isAlive()) {
			collisions->removeEntity(alienInfo->model->getId());
			alienInfo = aliens.erase(alienInfo);
		} else {
			alienInfo++;
		}
	}

	bool goDown = false;
	for(auto& alienInfo : aliens) {
		auto oldPosition = alienInfo.controller->getPosition();
		alienInfo.controller->update(dt);
		auto newPosition = alienInfo.controller->getPosition();

		if(newPosition.x - 16/2 <= 0) {
			goDown = true;
		}
		else if(newPosition.x + 16/2 >= 800) {
			goDown = true;
		}

		alienInfo.controller->setPosition(oldPosition);
	}

	for(auto& alienInfo : aliens) {
		if(goDown) {
			alienInfo.controller->moveDown(1.0);

			auto direction = alienInfo.controller->getDirection();
			if(direction == LEFT) {
				alienInfo.controller->setDirection(RIGHT);
			} else if(direction == RIGHT) {
				alienInfo.controller->setDirection(LEFT);
			}
		}

		alienInfo.controller->update(dt);
	}

	if(!spaceshipController->isAlive()) {
		std::cout << "We died" << std::endl;
	}

	timer += dt;
}

void SpaceInvaders::render(sf::RenderWindow& window)
{
	spaceshipView->render(window);

	for(auto& bulletInfo : bullets) {
		bulletInfo.view->render(window);
	}

	for(auto& alienInfo : aliens) {
		alienInfo.view->render(window);
	}
}

void SpaceInvaders::moveLeft(double dt)
{
	spaceshipController->moveLeft(dt);
}

void SpaceInvaders::moveRight(double dt)
{
	spaceshipController->moveRight(dt);
}

void SpaceInvaders::shoot()
{
	auto bulletPosition = spaceshipController->getPosition();

	auto bullet = std::make_shared<Bullet>(bulletPosition, 300, spaceship->getId());
	
	auto bulletController = std::make_shared<BulletController>(bullet);
	auto bulletView = std::make_shared<BulletGuiView>(bulletPosition);

	bullet->getCollidable().registerObserver(spaceshipController);
	bullet->getMovable().registerObserver(bulletView);
	bullet->getMovable().registerObserver(collisions);

	for(auto& alienInfo : aliens) {
		bullet->getCollidable().registerObserver(alienInfo.controller);
	}

	collisions->addEntity(bullet);

	BulletInfo info;
	info.model = bullet;
	info.controller = bulletController;
	info.view = bulletView;

	bullets.push_back(info);
}

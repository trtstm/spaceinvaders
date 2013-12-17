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
	: collisions(std::make_shared<CollisionSystem>())
{
	spaceship = std::make_shared<Spaceship>(Coordinate(400,580), 800);
	spaceship->setComponent<Collidable>(std::make_shared<Collidable>(spaceship->getId(), sf::Rect<double>(0.0, 0.0, 80.0, 40.0)));
	spaceship->setComponent<Livable>(std::make_shared<Livable>(spaceship->getId(), 1));

	spaceshipController = std::make_shared<SpaceshipController>(spaceship);
	spaceshipView = std::make_shared<SpaceshipGuiView>(spaceship);

	spaceship->getComponent<Livable>()->registerObserver(spaceshipController);

	collisions->addEntity(spaceship);


	for(unsigned int i = 0; i < 8; i++) {
		auto alien = std::make_shared<Alien>(Coordinate(160 + 25 + i * 60, 50));
		auto alienView = std::make_shared<AlienGuiView>(alien);

		AlienInfo alienInfo;
		alienInfo.model = alien;
		alienInfo.view = alienView;

		aliens.push_back(alienInfo);
	}
}

void SpaceInvaders::update(double dt)
{
	for(auto bulletInfo = bullets.begin(); bulletInfo != bullets.end();) {
		bulletInfo->controller->update(dt);

		if(bulletInfo->model->getComponent<Movable>()->getLocation().y < -50 || bulletInfo->model->getComponent<Movable>()->getLocation().y > 650) {
			collisions->removeEntity(bulletInfo->model);
			bulletInfo = bullets.erase(bulletInfo);
		} else {
			bulletInfo++;
		}
	}

	if(!spaceshipController->isAlive()) {
		std::cout << "We died" << std::endl;
	}
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
	auto bulletPosition = spaceshipController->getLocation();

	auto bullet = std::make_shared<Bullet>(bulletPosition, 300, spaceship->getId());
	bullet->setComponent<Collidable>(std::make_shared<BulletCollidable>(bullet->getId(), spaceship->getId(), sf::Rect<double>(0.0, 0.0, 4.0, 10.0)));
	
	auto bulletController = std::make_shared<BulletController>(bullet);
	auto bulletView = std::make_shared<BulletGuiView>(bullet);

	bullet->getComponent<Collidable>()->registerObserver(spaceshipController);
	bullet->getComponent<Movable>()->registerObserver(collisions);
	collisions->addEntity(bullet);

	BulletInfo info;
	info.model = bullet;
	info.controller = bulletController;
	info.view = bulletView;

	bullets.push_back(info);
}

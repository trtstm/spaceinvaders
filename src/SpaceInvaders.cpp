#include "SpaceInvaders.hpp"

#include "Coordinate.hpp"

#include "models/Spaceship.hpp"
#include "components/SpaceshipMovable.hpp"
#include "components/Collidable.hpp"
#include "components/BulletCollidable.hpp"
#include "components/Livable.hpp"

SpaceInvaders::SpaceInvaders()
	: collisions(std::make_shared<CollisionSystem>())
{
	spaceship = std::make_shared<Spaceship>(Coordinate(400,575), 800);
	spaceship->setComponent<Collidable>(std::make_shared<Collidable>(spaceship->getId(), sf::Rect<double>(0.0, 0.0, 120.0, 50.0)));
	spaceship->setComponent<Livable>(std::make_shared<Livable>(spaceship->getId(), 1));

	spaceshipController = std::make_shared<SpaceshipController>(spaceship);
	spaceshipView = std::make_shared<SpaceshipGuiView>(spaceship);

	spaceship->getComponent<Livable>()->registerObserver(spaceshipController);

	collisions->addEntity(spaceship);
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
	bullet->setComponent<Collidable>(std::make_shared<BulletCollidable>(bullet->getId(), sf::Rect<double>(0.0, 0.0, 10.0, 20.0)));
	
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

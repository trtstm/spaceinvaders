#include "SpaceInvaders.hpp"

#include "Coordinate.hpp"

#include "models/Spaceship.hpp"
#include "components/SpaceshipMovable.hpp"

SpaceInvaders::SpaceInvaders()
{
	auto spaceship = std::make_shared<Spaceship>(Coordinate(400,575), 800);

	spaceshipController = std::make_shared<SpaceshipController>(spaceship);
	spaceshipView = std::make_shared<SpaceshipGuiView>(spaceship);

	spaceship->getComponent<Movable>()->registerObserver(spaceshipView);
}

void SpaceInvaders::update(double dt)
{
	for(auto bulletInfo = bullets.begin(); bulletInfo != bullets.end();) {
		bulletInfo->controller->update(dt);

		if(bulletInfo->model->getComponent<Movable>()->getLocation().y < -50) {
			bulletInfo = bullets.erase(bulletInfo);
		} else {
			bulletInfo++;
		}
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

	auto bullet = std::make_shared<Bullet>(bulletPosition, 600);

	auto bulletController = std::make_shared<BulletController>(bullet);
	auto bulletView = std::make_shared<BulletGuiView>(bullet);

	BulletInfo info;
	info.model = bullet;
	info.controller = bulletController;
	info.view = bulletView;

	bullets.push_back(info);
}

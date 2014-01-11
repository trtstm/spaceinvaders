#include <cstdlib>
#include <ctime>

#include "SpaceInvaders.hpp"

#include "systems/CollisionSystem.hpp"
#include "Coordinate.hpp"

SpaceInvaders::SpaceInvaders(std::shared_ptr<Factory::EntityFactory> factory)
	:
		state(PLAYING),
		factory(factory),
		timer(0.0),
		level(1),
		resources(loadResources()),
		laserCannon(factory->newLaserCannon(Coordinate(400,580))),
		laserCannonController(laserCannon),
		laserCannonView(laserCannon->getPosition(), resources),
		scoreView(resources),
		levelView(resources),
		livesView(resources),
		spaceshipInfo(loadSpaceshipInfo())
{
	std::srand(std::time(0));

	laserCannon->registerMove(laserCannonView);
	collisions.addEntity(*laserCannon, true);

	loadAliens(16);

	for(unsigned int i = 0; i < 3; i++) {
		std::unique_ptr<BunkerInfo> bunker1(newBunkerInfo(Coordinate(133 + i * 266, 500)));
		bunkers.push_back(std::move(bunker1));
		bunkers.back()->modelLeft->registerCollision(bunkers.back()->viewLeft);
		bunkers.back()->modelMiddle->registerCollision(bunkers.back()->viewMiddle);
		bunkers.back()->modelRight->registerCollision(bunkers.back()->viewRight);
		collisions.addEntity(*bunkers.back()->modelLeft);
		collisions.addEntity(*bunkers.back()->modelMiddle);
		collisions.addEntity(*bunkers.back()->modelRight);
	}

	spaceshipInfo.controller.getSpaceship().registerMove(spaceshipInfo.view);
	spaceshipInfo.controller.getSpaceship().registerScore(score);
	collisions.addEntity(spaceshipInfo.controller.getSpaceship());
}

SpaceInvaders::~SpaceInvaders()
{
	laserCannon->unRegisterObservers();

	for(auto& row : aliens) {
		for(auto& alienInfo : row) {
			alienInfo->controller.getAlien().unRegisterObservers();
		}
	}

	for(auto& bulletInfo : alienBullets) {
		bulletInfo->controller.getBullet().unRegisterObservers();
	}

	for(auto& bunkerInfo : bunkers) {
		bunkerInfo->modelLeft->unRegisterObservers();
		bunkerInfo->modelMiddle->unRegisterObservers();
		bunkerInfo->modelRight->unRegisterObservers();
	}
}

void SpaceInvaders::loadAliens(double speed)
{
	for(auto& row : aliens) {
		for(auto& alienInfo : row) {
			collisions.removeEntity(alienInfo->controller.getAlien());
		}
	}

	aliens.clear();

	for(unsigned int y = 0; y < 5; y++) {
		aliens.push_back( std::vector< std::unique_ptr<AlienInfo> >() );

		for(unsigned int i = 0; i < 11; i++) {
			auto position = Coordinate(235 + i * 30, 100 + y * 30);
			auto alien = factory->newAlien(position, speed);
			auto alienController = Controller::AlienController(alien);
			auto alienView = View::AlienGuiView(position, resources);

			std::unique_ptr<AlienInfo> alienInfo(new AlienInfo{alienController, alienView});
			aliens[y].push_back(std::move(alienInfo));

			aliens[y].back()->controller.getAlien().registerMove(aliens[y].back()->view);
			aliens[y].back()->controller.getAlien().registerDied(aliens[y].back()->view);
			collisions.addEntity(aliens[y].back()->controller.getAlien(), true);
			aliens[y].back()->controller.getAlien().registerScore(score);
		}
	}
}

SpaceshipInfo SpaceInvaders::loadSpaceshipInfo()
{
	auto position = Coordinate(-50.0, 50);
	auto spaceship = factory->newSpaceship(position);
	auto spaceshipController = Controller::SpaceshipController(spaceship);
	auto spaceshipView = View::SpaceshipGuiView(position, resources);

	SpaceshipInfo info{spaceshipController, spaceshipView};

	return info;
}

Resources SpaceInvaders::loadResources()
{
	Resources rsc;

	if(!rsc.textures["lasercannon"].loadFromFile("../resources/lasercannon.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!rsc.textures["spaceship"].loadFromFile("../resources/spaceship.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!rsc.textures["invader1"].loadFromFile("../resources/invader1.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!rsc.textures["invader2"].loadFromFile("../resources/invader2.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!rsc.textures["explosion"].loadFromFile("../resources/explosion.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!rsc.textures["bunkerleft1"].loadFromFile("../resources/bunkerleft1.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!rsc.textures["bunkerleft2"].loadFromFile("../resources/bunkerleft2.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!rsc.textures["bunkerleft3"].loadFromFile("../resources/bunkerleft3.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!rsc.textures["bunkermiddle1"].loadFromFile("../resources/bunkermiddle1.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!rsc.textures["bunkermiddle2"].loadFromFile("../resources/bunkermiddle2.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!rsc.textures["bunkermiddle3"].loadFromFile("../resources/bunkermiddle3.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!rsc.textures["bunkerright1"].loadFromFile("../resources/bunkerright1.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!rsc.textures["bunkerright2"].loadFromFile("../resources/bunkerright2.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!rsc.textures["bunkerright3"].loadFromFile("../resources/bunkerright3.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!rsc.fonts["default"].loadFromFile("../resources/DejaVuSans.ttf")) {
		std::cout << "Could not load resources" << std::endl;
	}

	return rsc;
}

void SpaceInvaders::update(double dt)
{
	if(state == PAUSE || state == GAMEOVER) {
		return;
	}

	if(!laserCannon->isAlive()) {
		state = GAMEOVER;
		return;
	}

	laserCannonController.update(dt);

	if(spaceshipInfo.controller.isAlive() && spaceshipInfo.controller.getPosition().x < 800 + spaceshipInfo.controller.getSpaceship().getCollisionRectangle().width) {
		spaceshipInfo.controller.moveRight(dt);
		spaceshipClock.restart();
	} else {
		collisions.removeEntity(spaceshipInfo.controller.getSpaceship());
	}

	if(spaceshipClock.getElapsedTime().asSeconds() >= 10) {
		collisions.removeEntity(spaceshipInfo.controller.getSpaceship());
		spaceshipInfo = loadSpaceshipInfo();

		spaceshipInfo.controller.getSpaceship().registerMove(spaceshipInfo.view);
		spaceshipInfo.controller.getSpaceship().registerScore(score);
		collisions.addEntity(spaceshipInfo.controller.getSpaceship());

		spaceshipClock.restart();
	}

	if(aliveAliens() == 0) {
		level++;
		laserCannon->setHealth(laserCannon->getHealth() + 1);

		loadAliens(16.0 + 8.0 * level);
	}

	if(laserCannonBullet != nullptr) {
		laserCannonBullet->controller.update(dt);

		auto position = laserCannonBullet->controller.getPosition();
		auto rect = laserCannonBullet->controller.getCollisionRectangle();

		if(position.y - rect.height / 2 < 0 || !laserCannonBullet->controller.isAlive()) {
			collisions.removeEntity(laserCannonBullet->controller.getBullet());

			laserCannonBullet.reset();
		}
	}

	for(auto bulletInfo = alienBullets.begin(); bulletInfo != alienBullets.end();) {
		(*bulletInfo)->controller.update(dt);

		auto position = (*bulletInfo)->controller.getPosition();
		auto rect = (*bulletInfo)->controller.getCollisionRectangle();

		if(position.y - rect.height / 2 < 0 || !(*bulletInfo)->controller.isAlive()) {
			collisions.removeEntity((*bulletInfo)->controller.getBullet());

			bulletInfo = alienBullets.erase(bulletInfo);
		} else {
			bulletInfo++;
		}
	}

	if(timer >= 1.0) {
		alienShoot();
		timer = 0.0;
	}

	bool goDown = false;
	for(auto& row : aliens) {
		for(auto& alienInfo : row) {
			if(!alienInfo->controller.isAlive()) {
				collisions.removeEntity(alienInfo->controller.getAlien());
				continue;
			}

			auto oldPosition = alienInfo->controller.getPosition();
			alienInfo->controller.update(dt);
			auto newPosition = alienInfo->controller.getPosition();

			auto direction = alienInfo->controller.getDirection();

			if(direction == Controller::LEFT && newPosition.x - 16/2 <= 0) {
				goDown = true;
			}
			else if(direction == Controller::RIGHT && newPosition.x + 16/2 >= 800) {
				goDown = true;
			}

			alienInfo->controller.setPosition(oldPosition);
		}
	}

	for(auto& row : aliens) {
		for(auto& alienInfo : row) {
			if(!alienInfo->controller.isAlive()) {
				continue;
			}

			if(goDown) {
				alienInfo->controller.moveDown(1.0);

				auto direction = alienInfo->controller.getDirection();
				if(direction == Controller::LEFT) {
					alienInfo->controller.setDirection(Controller::RIGHT);
				} else if(direction == Controller::RIGHT) {
					alienInfo->controller.setDirection(Controller::LEFT);
				}
			} else {
				alienInfo->controller.update(dt);
			}
		}
	}

	for(auto& bunkerInfo : bunkers) {
		if(bunkerInfo->modelLeft->getHealth() <= 0) {
			collisions.removeEntity(*bunkerInfo->modelLeft);
		}

		if(bunkerInfo->modelRight->getHealth() <= 0) {
			collisions.removeEntity(*bunkerInfo->modelRight);
		}

		if(bunkerInfo->modelMiddle->getHealth() <= 0) {
			collisions.removeEntity(*bunkerInfo->modelMiddle);
		}
	}

	timer += dt;
}

unsigned int SpaceInvaders::aliveAliens() const
{
	unsigned int counter = 0;

	for(auto& row : aliens) {
		for(auto& alienInfo : row) {
			if(alienInfo->controller.isAlive()) {
				counter++;
			}
		}
	}

	return counter;
}

void SpaceInvaders::render(sf::RenderWindow& window, double dt)
{

	laserCannonView.render(window, resources, dt);

	scoreView.render(window, resources, score.getScore());
	levelView.render(window, resources, level);
	livesView.render(window, resources, laserCannon->getHealth());

	if(laserCannonBullet != nullptr) {
		laserCannonBullet->view.render(window);
	}

	for(auto& bulletInfo : alienBullets) {
		bulletInfo->view.render(window);
	}

	for(auto& row : aliens) {
		for(auto& alienInfo : row) {
			alienInfo->view.render(window, resources, dt);
		}
	}

	for(auto& bunkerInfo : bunkers) {
		if(bunkerInfo->modelLeft->getHealth() > 0) {
			bunkerInfo->viewLeft.render(window, resources, dt);
		}

		if(bunkerInfo->modelRight->getHealth() > 0) {
			bunkerInfo->viewRight.render(window, resources, dt);
		}

		if(bunkerInfo->modelMiddle->getHealth() > 0) {
			bunkerInfo->viewMiddle.render(window, resources, dt);
		}
	}

	if(spaceshipInfo.controller.isAlive()) {
		spaceshipInfo.view.render(window, resources);
	}
}

BunkerInfo* SpaceInvaders::newBunkerInfo(const Coordinate position) const
{
	Coordinate bunkerLeftPos = position;
	bunkerLeftPos.x -= 42.0 / 2.0 - 10.0 / 2.0;
	bunkerLeftPos.y -= 32.0 / 2.0;

	auto bunkerLeft = std::unique_ptr<Model::BunkerLeft>(factory->newBunkerLeft(bunkerLeftPos));
	auto bunkerLeftView = View::BunkerLeftGuiView(bunkerLeftPos, resources);

	Coordinate bunkerMiddlePos = bunkerLeftPos;
	bunkerMiddlePos.x += 16;
	bunkerMiddlePos.y -= 2.0;
	auto bunkerMiddle =  std::unique_ptr<Model::BunkerMiddle>(factory->newBunkerMiddle(bunkerMiddlePos));
	auto bunkerMiddleView = View::BunkerMiddleGuiView(bunkerMiddlePos, resources);

	Coordinate bunkerRightPos = position;
	bunkerRightPos.x += 42.0 / 2.0 - 10.0 / 2.0;
	bunkerRightPos.y -= 32.0 / 2.0;
	auto bunkerRight =  std::unique_ptr<Model::BunkerRight>(factory->newBunkerRight(bunkerRightPos));
	auto bunkerRightView = View::BunkerRightGuiView(bunkerRightPos, resources);

	auto bunkerInfo = new BunkerInfo{std::move(bunkerLeft), bunkerLeftView, std::move(bunkerMiddle), bunkerMiddleView, std::move(bunkerRight), bunkerRightView};

	return bunkerInfo;
}

void SpaceInvaders::alienShoot()
{
	std::vector<AlienInfo*> possibleAliens;
	for(unsigned int x = 0; x < aliens[0].size(); x++) {
		// Get the alien at the lowest row in this column.

		for(unsigned int y = 0; y < aliens.size(); y++) {
			if(aliens[aliens.size() - y - 1][x]->controller.isAlive()) {
				possibleAliens.push_back(aliens[aliens.size() - y - 1][x].get());
				break;
			}
		}
	}

	if(possibleAliens.size() == 0) {
		return;
	}

	// Should these aliens shoot?
	auto shouldShoot = ((std::rand() % 3) == 0);

	if(shouldShoot) {
		auto randX = std::rand() % possibleAliens.size();

		auto bulletPosition = possibleAliens[randX]->controller.getPosition();

		auto bulletController = Controller::BulletController(factory->newBullet(bulletPosition, -300, possibleAliens[randX]->controller.getAlien().getId()));
		auto bulletView = View::BulletGuiView(bulletPosition);

		std::unique_ptr<BulletInfo> info(new BulletInfo{bulletController, bulletView});
		alienBullets.push_back(std::move(info));

		alienBullets.back()->controller.getBullet().registerMove(alienBullets.back()->view);
		collisions.addEntity(alienBullets.back()->controller.getBullet(), true);
	}
}

void SpaceInvaders::shoot()
{
	if(laserCannonBullet != nullptr) {
		return;
	}

	auto bulletPosition = laserCannon->getPosition();

	auto bulletController = Controller::BulletController(factory->newBullet(bulletPosition, 300, laserCannon->getId()));
	auto bulletView = View::BulletGuiView(bulletPosition);

	laserCannonBullet.reset(new BulletInfo{bulletController, bulletView});

	laserCannonBullet->controller.getBullet().registerMove(laserCannonBullet->view);
	collisions.addEntity(laserCannonBullet->controller.getBullet(), true);

}

bool SpaceInvaders::shouldStop() const
{
	if(state == GAMEOVER) {
		return true;
	}

	return false;
}

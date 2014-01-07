#include <cstdlib>
#include <ctime>

#include "SpaceInvaders.hpp"

#include "systems/CollisionSystem.hpp"
#include "Coordinate.hpp"

SpaceInvaders::SpaceInvaders(std::shared_ptr<EntityFactory> factory)
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
		spaceshipInfo(loadSpaceshipInfo())
{
	std::srand(std::time(0));

	laserCannon->registerMove(laserCannonView);
	collisions.addEntity(*laserCannon, true);

	loadAliens(16);

	for(unsigned int i = 0; i < 3; i++) {
		std::unique_ptr<BunkerInfo> bunker1(newBunkerInfo(Coordinate(133 + i * 266, 500)));
		bunkers.push_back(std::move(bunker1));
		bunkers.back()->modelLeft.registerCollision(bunkers.back()->viewLeft);
		bunkers.back()->modelMiddle.registerCollision(bunkers.back()->viewMiddle);
		bunkers.back()->modelRight.registerCollision(bunkers.back()->viewRight);
		collisions.addEntity(bunkers.back()->modelLeft);
		collisions.addEntity(bunkers.back()->modelMiddle);
		collisions.addEntity(bunkers.back()->modelRight);
	}

	spaceshipInfo.controller.getSpaceship().registerMove(spaceshipInfo.view);
	spaceshipInfo.controller.getSpaceship().registerDied(score);
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

	for(auto& bulletInfo : bullets) {
		bulletInfo->controller.getBullet().unRegisterObservers();
	}

	for(auto& bunkerInfo : bunkers) {
		bunkerInfo->modelLeft.unRegisterObservers();
		bunkerInfo->modelMiddle.unRegisterObservers();
		bunkerInfo->modelRight.unRegisterObservers();
	}
}

void SpaceInvaders::loadAliens(double speed)
{
	for(auto& row : aliens) {
		for(auto& alienInfo : row) {
			collisions.removeEntity(alienInfo->controller.getAlien().getId());
		}
	}

	aliens.clear();

	for(unsigned int y = 0; y < 5; y++) {
		aliens.push_back( std::vector< std::unique_ptr<AlienInfo> >() );

		for(unsigned int i = 0; i < 11; i++) {
			auto position = Coordinate(235 + i * 30, 100 + y * 30);
			auto alien = factory->newAlien(position, speed);
			auto alienController = AlienController(alien);
			auto alienView = AlienGuiView(position, resources);

			std::unique_ptr<AlienInfo> alienInfo(new AlienInfo{alienController, alienView});
			aliens[y].push_back(std::move(alienInfo));

			aliens[y].back()->controller.getAlien().registerMove(aliens[y].back()->view);
			aliens[y].back()->controller.getAlien().registerDied(aliens[y].back()->view);
			collisions.addEntity(aliens[y].back()->controller.getAlien(), true);
			aliens[y].back()->controller.getAlien().registerDied(score);
		}
	}
}

SpaceshipInfo SpaceInvaders::loadSpaceshipInfo()
{
	auto position = Coordinate(-50.0, 50);
	auto spaceship = factory->newSpaceship(position);
	auto spaceshipController = SpaceshipController(spaceship);
	auto spaceshipView = SpaceshipGuiView(position, resources);

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

	if(!laserCannonController.isAlive()) {
		state = GAMEOVER;
		return;
	}

	if(spaceshipInfo.controller.isAlive() && spaceshipInfo.controller.getPosition().x < 800 + spaceshipInfo.controller.getSpaceship().getCollisionRectangle().width) {
		spaceshipInfo.controller.moveRight(dt);
		spaceshipClock.restart();
	} else {
		collisions.removeEntity(spaceshipInfo.controller.getSpaceship().getId());
	}

	if(spaceshipClock.getElapsedTime().asSeconds() >= 10) {
		collisions.removeEntity(spaceshipInfo.controller.getSpaceship().getId());
		spaceshipInfo = loadSpaceshipInfo();

		spaceshipInfo.controller.getSpaceship().registerMove(spaceshipInfo.view);
		spaceshipInfo.controller.getSpaceship().registerDied(score);
		collisions.addEntity(spaceshipInfo.controller.getSpaceship());

		spaceshipClock.restart();
	}

	if(aliveAliens() == 0) {
		level++;

		loadAliens(16.0 + 8.0 * level);
	}

	for(auto bulletInfo = bullets.begin(); bulletInfo != bullets.end();) {
		(*bulletInfo)->controller.update(dt);

		auto position = (*bulletInfo)->controller.getPosition();
		auto rect = (*bulletInfo)->controller.getCollisionRectangle();

		if(position.y - rect.height / 2 < 0 || !(*bulletInfo)->controller.isAlive()) {
			collisions.removeEntity((*bulletInfo)->controller.getBullet().getId());

			bulletInfo = bullets.erase(bulletInfo);
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
				collisions.removeEntity(alienInfo->controller.getAlien().getId());
				continue;
			}

			auto oldPosition = alienInfo->controller.getPosition();
			alienInfo->controller.update(dt);
			auto newPosition = alienInfo->controller.getPosition();

			auto direction = alienInfo->controller.getDirection();

			if(direction == LEFT && newPosition.x - 16/2 <= 0) {
				goDown = true;
			}
			else if(direction == RIGHT && newPosition.x + 16/2 >= 800) {
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
				if(direction == LEFT) {
					alienInfo->controller.setDirection(RIGHT);
				} else if(direction == RIGHT) {
					alienInfo->controller.setDirection(LEFT);
				}
			} else {
				alienInfo->controller.update(dt);
			}
		}
	}

	for(auto& bunkerInfo : bunkers) {
		if(bunkerInfo->modelLeft.getHealth() <= 0) {
			collisions.removeEntity(bunkerInfo->modelLeft.getId());
		}

		if(bunkerInfo->modelRight.getHealth() <= 0) {
			collisions.removeEntity(bunkerInfo->modelRight.getId());
		}

		if(bunkerInfo->modelMiddle.getHealth() <= 0) {
			collisions.removeEntity(bunkerInfo->modelMiddle.getId());
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

	for(auto& bulletInfo : bullets) {
		bulletInfo->view.render(window);
	}

	for(auto& row : aliens) {
		for(auto& alienInfo : row) {
			alienInfo->view.render(window, resources, dt);
		}
	}

	for(auto& bunkerInfo : bunkers) {
		if(bunkerInfo->modelLeft.getHealth() > 0) {
			bunkerInfo->viewLeft.render(window, resources, dt);
		}

		if(bunkerInfo->modelRight.getHealth() > 0) {
			bunkerInfo->viewRight.render(window, resources, dt);
		}

		if(bunkerInfo->modelMiddle.getHealth() > 0) {
			bunkerInfo->viewMiddle.render(window, resources, dt);
		}
	}

	if(spaceshipInfo.controller.isAlive()) {
		spaceshipInfo.view.render(window, resources);
	}
}

void SpaceInvaders::moveLeft(double dt)
{
	laserCannonController.moveLeft(dt);
}

void SpaceInvaders::moveRight(double dt)
{
	laserCannonController.moveRight(dt);
}

BunkerInfo* SpaceInvaders::newBunkerInfo(const Coordinate position) const
{
	Coordinate bunkerLeftPos = position;
	bunkerLeftPos.x -= 42.0 / 2.0 - 10.0 / 2.0;
	bunkerLeftPos.y -= 32.0 / 2.0;

	auto bunkerLeft = BunkerLeft(bunkerLeftPos);
	auto bunkerLeftView = BunkerLeftGuiView(bunkerLeftPos, resources);

	Coordinate bunkerMiddlePos = bunkerLeftPos;
	bunkerMiddlePos.x += 16;
	bunkerMiddlePos.y -= 2.0;
	auto bunkerMiddle = BunkerMiddle(bunkerMiddlePos);
	auto bunkerMiddleView = BunkerMiddleGuiView(bunkerMiddlePos, resources);

	Coordinate bunkerRightPos = position;
	bunkerRightPos.x += 42.0 / 2.0 - 10.0 / 2.0;
	bunkerRightPos.y -= 32.0 / 2.0;
	auto bunkerRight = BunkerRight(bunkerRightPos);
	auto bunkerRightView = BunkerRightGuiView(bunkerRightPos, resources);

	auto bunkerInfo = new BunkerInfo{bunkerLeft, bunkerLeftView, bunkerMiddle, bunkerMiddleView, bunkerRight, bunkerRightView};

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

		auto bulletController = BulletController(Bullet(bulletPosition, -300, possibleAliens[randX]->controller.getAlien().getId()));
		auto bulletView = BulletGuiView(bulletPosition);

		std::unique_ptr<BulletInfo> info(new BulletInfo{bulletController, bulletView});
		bullets.push_back(std::move(info));

		bullets.back()->controller.getBullet().registerMove(bullets.back()->view);
		collisions.addEntity(bullets.back()->controller.getBullet(), true);
	}
}

void SpaceInvaders::shoot()
{
	auto bulletPosition = laserCannonController.getPosition();

	auto bulletController = BulletController(Bullet(bulletPosition, 300, laserCannon->getId()));
	auto bulletView = BulletGuiView(bulletPosition);

	std::unique_ptr<BulletInfo> info(new BulletInfo{bulletController, bulletView});
	bullets.push_back(std::move(info));

	bullets.back()->controller.getBullet().registerMove(bullets.back()->view);
	collisions.addEntity(bullets.back()->controller.getBullet(), true);

}

bool SpaceInvaders::shouldStop() const
{
	if(state == GAMEOVER) {
		return true;
	}

	return false;
}

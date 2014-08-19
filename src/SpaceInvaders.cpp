#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

#include "SpaceInvaders.hpp"

#include "exceptions/FileException.hpp"
#include "systems/CollisionSystem.hpp"
#include "Coordinate.hpp"


SpaceInvaders::SpaceInvaders(GlobalLoader globalConfig, std::shared_ptr<Factory::EntityFactory> factory)
	:
		globalConfig(globalConfig),
		state(MENU),
		factory(factory),
		timer(0.0),
		level(1),
		resources(loadResources()),
		player2(nullptr),
		scoreView(resources, globalConfig),
		levelView(resources, globalConfig),
		livesView(resources, globalConfig),
		spaceshipInfo(loadSpaceshipInfo())
{
	std::srand(std::time(0));

	highscores.load("../resources/config/highscores.json");

	levels = globalConfig.getLevels();

	menuView = std::unique_ptr<View::MenuView>(new View::MenuView(resources, globalConfig, highscores.getHighscores()));
	menuController = std::unique_ptr<Controller::MenuController>(new Controller::MenuController(this));
	menuController->registerMenuChange(*menuView.get());
	menuController->registerMenuSelection(*menuView.get());
}

SpaceInvaders::~SpaceInvaders()
{
}

void SpaceInvaders::loadAliens()
{

	// Remove existing aliens from collision system
	for(auto& row : aliens) {
		for(auto& alienInfo : row) {
			if(alienInfo == nullptr) {
				continue;
			}

			collisions.removeEntity(alienInfo->controller.getAlien());
		}
	}

	aliens.clear();

	if(levels.size() < 1) {
		return;
	}

	// Update speed with the level multiplier
	double originalSpeed = globalConfig.get<double>("invader.speed");
	globalConfig.put<double>("invader.speed", originalSpeed * levels[0].getSpeed());

	int width = levels[0].getWidth();
	int height = levels[0].getHeight();
	auto enemies = levels[0].getEnemies();

	// Add invaders for the level
	for(int y = 0; y < height; y++) {
		aliens.push_back( std::vector< std::unique_ptr<AlienInfo> >() );

		for(int x = 0; x < width; x++) {
			if(enemies[y][x] != 1) {
				aliens[y].push_back(nullptr);
				continue;
			}

			auto position = Coordinate(globalConfig.getResolutionX() - width * 30 + x * 30, globalConfig.getResolutionY() / 8 + y * 30);
			auto alien = factory->newAlien(position, globalConfig);
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

	// Invaders are created now, reset the speed
	globalConfig.put<double>("invader.speed", originalSpeed);
}

SpaceshipInfo SpaceInvaders::loadSpaceshipInfo()
{
	// Create a spaceship outside the screen
	auto position = Coordinate(-globalConfig.get<double>("spaceship.dimensions.x"), 50);
	auto spaceship = factory->newSpaceship(position, globalConfig);
	auto spaceshipController = Controller::SpaceshipController(spaceship);
	auto spaceshipView = View::SpaceshipGuiView(position, resources);

	SpaceshipInfo info{spaceshipController, spaceshipView};

	return info;
}

Resources SpaceInvaders::loadResources()
{
	auto graphics = globalConfig.getGraphics();
	auto fonts = globalConfig.getFonts();

	Resources rsc;

	for(const auto& kv : graphics) {
		if(kv.second == "") {
			throw FileException("no file given for " + kv.first);
		}

		if(!rsc.textures[kv.first].loadFromFile("../resources/" + kv.second)) {
			throw FileException(kv.second);
		}
	}

	for(const auto& kv : fonts) {
		if(kv.second == "") {
			throw FileException("no file given for " + kv.first);
		}

		if(!rsc.fonts[kv.first].loadFromFile("../resources/" + kv.second)) {
			throw FileException(kv.second);
		}
	}

	return rsc;
}

void SpaceInvaders::update(double dt)
{
	menuController->update(dt);

	if(state == PAUSE || state == GAMEOVER) {
		return;
	}

	// If we are in menu, we don't need to update the game
	if(state == MENU) {
		return;
	}

	// Are player(s) still alive?
	auto health = player1->getHealth();
	if(player2) {
		health += player2->getHealth();
	}
	if(health <= 0) {
		gameOver();
		return;
	}

	// Update the players
	player1Controller->update(dt);
	if(player2) {
		player2Controller->update(dt);
	}

	// Spaceship is still on screen
	if(spaceshipInfo.controller.isAlive() && spaceshipInfo.controller.getPosition().x < globalConfig.getResolutionX() + spaceshipInfo.controller.getSpaceship().getCollisionRectangle().width) {
		spaceshipInfo.controller.moveRight(dt);
		spaceshipClock.restart();
	} else {
		// We are offscreen, remove from collisions
		collisions.removeEntity(spaceshipInfo.controller.getSpaceship());
	}

	// Should we spawn the spaceship?
	if(spaceshipClock.getElapsedTime().asSeconds() >= globalConfig.get<int>("spaceship.spawntime")) {
		collisions.removeEntity(spaceshipInfo.controller.getSpaceship());
		spaceshipInfo = loadSpaceshipInfo();

		spaceshipInfo.controller.getSpaceship().registerMove(spaceshipInfo.view);
		spaceshipInfo.controller.getSpaceship().registerScore(score);
		collisions.addEntity(spaceshipInfo.controller.getSpaceship());

		spaceshipClock.restart();
	}


	// We killed all aliens
	if(aliveAliens() == 0) {
		level++;
		player1->setHealth(player1->getHealth() + 1);

		// Select next level
		if(levels.size() > 0) {
			levels.erase(levels.begin());
		}
		if(levels.size() < 1) {
			std::cout << "No more levels" << std::endl;
			gameOver();
			return;
		}

		loadAliens();
	}

	// Players bullets
	for(auto& bl : laserCannonBullet) {
		bl.second->controller.update(dt);
		auto position = bl.second->controller.getPosition();
		auto rect = bl.second->controller.getCollisionRectangle();

		// We are offscreen or bullet has hit something
		if(position.y - rect.height / 2 < 0 || !bl.second->controller.isAlive()) {
			collisions.removeEntity(bl.second->controller.getBullet());

			laserCannonBullet.erase(bl.first);
		}
	}

	// Invader bullets
	for(auto bulletInfo = alienBullets.begin(); bulletInfo != alienBullets.end();) {
		(*bulletInfo)->controller.update(dt);

		auto position = (*bulletInfo)->controller.getPosition();
		auto rect = (*bulletInfo)->controller.getCollisionRectangle();

		// We are offscreen or bullet has hit something
		if(position.y - rect.height / 2 < 0 || !(*bulletInfo)->controller.isAlive()) {
			collisions.removeEntity((*bulletInfo)->controller.getBullet());

			bulletInfo = alienBullets.erase(bulletInfo);
		} else {
			bulletInfo++;
		}
	}

	// Let invaders shoot randomly
	if(timer >= globalConfig.get<double>("invader.shoottime")) {
		alienShoot();
		timer = 0.0;
	}

	// Check if the invaders should move down
	bool goDown = false;
	for(auto& row : aliens) {
		for(auto& alienInfo : row) {
			if(alienInfo == nullptr) {
				continue;
			}

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
			else if(direction == Controller::RIGHT && newPosition.x + 16/2 >= globalConfig.getResolutionX()) {
				goDown = true;
			}

			alienInfo->controller.setPosition(oldPosition);
		}
	}

	// Move the invaders down
	for(auto& row : aliens) {
		for(auto& alienInfo : row) {
			if(alienInfo == nullptr) {
				continue;
			}

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

	// Remove bunkers from collisions if they are broken down
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
			if(alienInfo == nullptr) {
				continue;
			}

			if(alienInfo->controller.isAlive()) {
				counter++;
			}
		}
	}

	return counter;
}

void SpaceInvaders::render(sf::RenderWindow& window, double dt)
{
	if(state == MENU) {
		menuView->render(window);
		return;
	}

	if(state == GAMEOVER) {
		return;
	}

	player1View->render(window, resources, dt);

	if(player2) {
		player2View->render(window, resources, dt);
	}

	scoreView.render(window, resources, score.getScore());
	levelView.render(window, resources, level);
	auto health = player1->getHealth();
	if(player2) {
		health += player2->getHealth();
	}
	livesView.render(window, resources, health);

	for(auto& bl : laserCannonBullet) {
		bl.second->view.render(window);
	}

	for(auto& bulletInfo : alienBullets) {
		bulletInfo->view.render(window);
	}

	for(auto& row : aliens) {
		for(auto& alienInfo : row) {
			if(alienInfo == nullptr) {
				continue;
			}

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
	// Get the width of a bunker
	double totalX = globalConfig.get<int>("bunkerleft.dimensions.x") + globalConfig.get<int>("bunkermiddle.dimensions.x") + globalConfig.get<int>("bunkerright.dimensions.x");

	Coordinate bunkerLeftPos = position;
	bunkerLeftPos.x -= totalX / 2.0 - globalConfig.get<int>("bunkerleft.dimensions.x") / 2.0;
	bunkerLeftPos.y -= globalConfig.get<int>("bunkerleft.dimensions.y") / 2.0;

	auto bunkerLeft = std::unique_ptr<Model::BunkerLeft>(factory->newBunkerLeft(bunkerLeftPos, globalConfig));
	auto bunkerLeftView = View::BunkerLeftGuiView(bunkerLeftPos, resources);

	Coordinate bunkerMiddlePos = bunkerLeftPos;
	bunkerMiddlePos.x += (totalX - globalConfig.get<int>("bunkerleft.dimensions.x")) / 2.0;
	bunkerMiddlePos.y -= 2.0;
	auto bunkerMiddle =  std::unique_ptr<Model::BunkerMiddle>(factory->newBunkerMiddle(bunkerMiddlePos, globalConfig));
	auto bunkerMiddleView = View::BunkerMiddleGuiView(bunkerMiddlePos, resources);

	Coordinate bunkerRightPos = position;
	bunkerRightPos.x += totalX / 2.0 - globalConfig.get<int>("bunkerright.dimensions.x") / 2.0;
	bunkerRightPos.y -= globalConfig.get<int>("bunkerright.dimensions.y") / 2.0;
	auto bunkerRight =  std::unique_ptr<Model::BunkerRight>(factory->newBunkerRight(bunkerRightPos, globalConfig));
	auto bunkerRightView = View::BunkerRightGuiView(bunkerRightPos, resources);

	auto bunkerInfo = new BunkerInfo{std::move(bunkerLeft), bunkerLeftView, std::move(bunkerMiddle), bunkerMiddleView, std::move(bunkerRight), bunkerRightView};

	return bunkerInfo;
}

void SpaceInvaders::alienShoot()
{
	std::vector<AlienInfo*> possibleAliens;

	// Invaders can only shoot if they are the lowest in their column
	for(unsigned int x = 0; x < aliens[0].size(); x++) {
		for(unsigned int y = aliens.size(); y-- > 0;) {
			if(aliens[y][x] == nullptr) {
				continue;
			}

			if(aliens[y][x]->controller.isAlive()) {
				possibleAliens.push_back(aliens[y][x].get());
				break;
			}


		}
	}


	if(possibleAliens.size() == 0) {
		return;
	}

	int nrDelete = possibleAliens.size() - globalConfig.get<int>("invader.maxshots");
	if(nrDelete < 0) {
		nrDelete = 0;
	}
	nrDelete = std::min(nrDelete, static_cast<int>(possibleAliens.size()));
	for(int i = 0; i < nrDelete; i++) {
		auto deletePos = std::rand() % possibleAliens.size();

		possibleAliens.erase(possibleAliens.begin() + deletePos);
	}

	// Should these aliens shoot?
	double chance = std::min(globalConfig.get<double>("invader.shootchance"), 1.0) * 100.0;
	if(chance < 0) {
		chance = 0;
	}

	for(auto& alien : possibleAliens) {
		bool shouldShoot = ((std::rand() % 100) < chance);

		if(shouldShoot) {
			auto bulletPosition = alien->controller.getPosition();

			auto bulletController = Controller::BulletController(factory->newBullet(bulletPosition, -300, Model::Bullet::ENEMY, alien->controller.getAlien().getId()));
			auto bulletView = View::BulletGuiView(bulletPosition);

			std::unique_ptr<BulletInfo> info(new BulletInfo{bulletController, bulletView});
			alienBullets.push_back(std::move(info));

			alienBullets.back()->controller.getBullet().registerMove(alienBullets.back()->view);
			collisions.addEntity(alienBullets.back()->controller.getBullet(), true);
		}
	}
}

void SpaceInvaders::shoot(Model::LaserCannon* owner)
{
	// Owner already has a bullet flying around
	if(laserCannonBullet.count(owner->getId()) == 1) {
		return;
	}

	auto bulletPosition = owner->getPosition();

	auto bulletController = Controller::BulletController(factory->newBullet(bulletPosition, 300, Model::Bullet::FRIENDLY, owner->getId()));
	auto bulletView = View::BulletGuiView(bulletPosition);

	laserCannonBullet[owner->getId()] = std::unique_ptr<BulletInfo>(new BulletInfo{bulletController, bulletView});

	laserCannonBullet[owner->getId()]->controller.getBullet().registerMove(laserCannonBullet[owner->getId()]->view);
	collisions.addEntity(laserCannonBullet[owner->getId()]->controller.getBullet(), true);

}

bool SpaceInvaders::shouldStop() const
{
	if(state == GAMEOVER) {
		return true;
	}

	return false;
}

void SpaceInvaders::setState(State newState)
{
	state = newState;
}

State SpaceInvaders::getState() const
{
	return state;
}

void SpaceInvaders::event(sf::Event event)
{
	menuController->event(event);
}

void SpaceInvaders::initGame(int players)
{
	if(players < 1 || players > 2) {
		players = 1;
	}

	collisions = System::CollisionSystem();
	score = System::ScoreSystem();
	laserCannonBullet.clear();
	alienBullets.clear();
	aliens.clear();
	bunkers.clear();

	player1 = 0;
	player1Controller.reset();
	player1View.reset();

	player2 = 0;
	player2Controller.reset();
	player2View.reset();

	// Controller takes care of freeing player1
	player1 = factory->newLaserCannon(Coordinate(globalConfig.getResolutionX() / 2 - 100, globalConfig.getResolutionY() - 50), globalConfig);
	player1Controller = std::unique_ptr<Controller::LaserCannonController>(new Controller::LaserCannonController(player1, Controller::LaserCannonController::ARROWS, this));
	player1View = std::unique_ptr<View::LaserCannonGuiView>(new View::LaserCannonGuiView(player1->getPosition(), resources));
	player1->registerMove(*player1View);
	collisions.addEntity(*player1, true);

	if(players == 2) {
		player2 = factory->newLaserCannon(Coordinate(globalConfig.getResolutionX() / 2 + 100, globalConfig.getResolutionY() - 50), globalConfig);
		player2Controller = std::unique_ptr<Controller::LaserCannonController>(new Controller::LaserCannonController(player2, Controller::LaserCannonController::WASD, this));
		player2View = std::unique_ptr<View::LaserCannonGuiView>(new View::LaserCannonGuiView(player2->getPosition(), resources));
		player2->registerMove(*player2View);
		collisions.addEntity(*player2, true);
	}

	loadAliens();

	bunkers.clear();
	auto unit = globalConfig.getResolutionX() / 5;
	for(unsigned int i = 0; i < 3; i++) {
		std::unique_ptr<BunkerInfo> bunker1(newBunkerInfo(Coordinate(unit * 2 - unit / 2 + i * unit, globalConfig.getResolutionY() - 100)));
		bunkers.push_back(std::move(bunker1));
		bunkers.back()->modelLeft->registerCollision(bunkers.back()->viewLeft);
		bunkers.back()->modelMiddle->registerCollision(bunkers.back()->viewMiddle);
		bunkers.back()->modelRight->registerCollision(bunkers.back()->viewRight);
		collisions.addEntity(*bunkers.back()->modelLeft);
		collisions.addEntity(*bunkers.back()->modelMiddle);
		collisions.addEntity(*bunkers.back()->modelRight);
	}

	spaceshipInfo = loadSpaceshipInfo();

	spaceshipInfo.controller.getSpaceship().registerMove(spaceshipInfo.view);
	spaceshipInfo.controller.getSpaceship().registerScore(score);
	collisions.addEntity(spaceshipInfo.controller.getSpaceship());
}

void SpaceInvaders::gameOver()
{
		std::cout << "Game over! Score: " << score.getScore() << std::endl;
		highscores.addHighscore(score.getScore(), (player2) ? 2 : 1);
		menuView->setHighscores(highscores.getHighscores());
		highscores.save();

		state = PAUSE;
}

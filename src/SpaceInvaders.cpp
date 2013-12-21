#include "SpaceInvaders.hpp"

#include "systems/CollisionSystem.hpp"
#include "Coordinate.hpp"

#include "components/Collidable.hpp"
#include "components/Livable.hpp"

SpaceInvaders::SpaceInvaders()
	:
		timer(0.0),
		resources(loadResources()),
		spaceship(Coordinate(400,580)),
		spaceshipController(spaceship),
		spaceshipView(spaceship.getPosition(), resources),
		scoreView(resources)
{

	spaceship.registerObserver(spaceshipView);

	collisions.addEntity(spaceship);


	for(unsigned int y = 0; y < 5; y++) {
		aliens.push_back( std::vector< std::unique_ptr<AlienInfo> >() );

		for(unsigned int i = 0; i < 11; i++) {
			auto position = Coordinate(235 + i * 30, 50 + y * 30);
			auto alien = Alien(position);
			auto alienController = AlienController(alien);
			auto alienView = AlienGuiView(position, resources);

			std::unique_ptr<AlienInfo> alienInfo(new AlienInfo{alienController, alienView});
			aliens[y].push_back(std::move(alienInfo));

			aliens[y].back()->controller.getAlien().registerObserver(aliens[y].back()->view);
			collisions.addEntity(aliens[y].back()->controller.getAlien());
			aliens[y].back()->controller.getAlien().registerObserver(score);
		}
	}

	Coordinate bunkerPos(400, 300);
	auto bunker = Bunker(bunkerPos);
	auto bunkerView = BunkerGuiView(bunkerPos);
	std::unique_ptr<BunkerInfo> bunkerInfo(new BunkerInfo{bunker, bunkerView});
	bunkers.push_back(std::move(bunkerInfo));
	collisions.addEntity(bunkers.back()->model);
	
}

SpaceInvaders::~SpaceInvaders()
{
	spaceship.unRegisterObservers();
	collisions.removeEntity(spaceship.getId());

	for(auto& row : aliens) {
		for(auto& alienInfo : row) {
			alienInfo->controller.getAlien().unRegisterObservers();
		}
	}

	for(auto& bulletInfo : bullets) {
		bulletInfo->controller.getBullet().unRegisterObservers();
	}

	for(auto& bunkerInfo : bunkers) {
		bunkerInfo->model.unRegisterObservers();
	}
}

Resources SpaceInvaders::loadResources()
{
	Resources rsc;

	if(!rsc.textures["lasercannon"].loadFromFile("../resources/lasercannon.png")) {
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

	if(!rsc.textures["blockleft"].loadFromFile("../resources/blockleft.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!rsc.textures["blockmiddle"].loadFromFile("../resources/blockmiddle.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!rsc.textures["blockright"].loadFromFile("../resources/blockright.png")) {
		std::cout << "Could not load resources" << std::endl;
	}

	if(!rsc.fonts["default"].loadFromFile("../resources/DejaVuSans.ttf")) {
		std::cout << "Could not load resources" << std::endl;
	}

	return rsc;
}

void SpaceInvaders::update(double dt)
{
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

	for(auto& row : aliens) {
		for(auto& alienInfo : row) {
			if(!alienInfo->controller.isAlive()) {
				collisions.removeEntity(alienInfo->controller.getAlien().getId());

				for(auto& bulletInfo : bullets) {
					bulletInfo->controller.getBullet().unRegisterObserver(alienInfo->controller);
				}
			}
		}
	}

	if(timer >= 1.0) {
		bool goDown = false;
		for(auto& row : aliens) {
			for(auto& alienInfo : row) {
				if(!alienInfo->controller.isAlive()) {
					continue;
				}

				auto oldPosition = alienInfo->controller.getPosition();
				alienInfo->controller.update(1.0);
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
					alienInfo->controller.update(1.0);
				}
			}
		}

		timer = 0.0;
	}

	timer += dt;
}

void SpaceInvaders::render(sf::RenderWindow& window, double dt)
{
	spaceshipView.render(window, resources, dt);

	scoreView.render(window, resources, score.getScore());

	for(auto& bulletInfo : bullets) {
		bulletInfo->view.render(window);
	}

	for(auto& row : aliens) {
		for(auto& alienInfo : row) {
			alienInfo->view.render(window, resources, dt);
		}
	}

	for(auto& bunkerInfo : bunkers) {
		bunkerInfo->view.render(window, resources, dt);
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

void SpaceInvaders::alienShoot()
{
	for(auto y = aliens.size() -1; y >= 0; y--) {

	}
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

	for(auto& row : aliens) {
		for(auto& alienInfo : row) {
			if(!alienInfo->controller.isAlive()) {
				continue;
			}

			bullets.back()->controller.getBullet().registerObserver(alienInfo->controller);
		}
	}

	for(auto& bunkerInfo : bunkers) {
		bullets.back()->controller.getBullet().registerObserver(bunkerInfo->view);
	}

	collisions.addEntity(bullets.back()->controller.getBullet());

}

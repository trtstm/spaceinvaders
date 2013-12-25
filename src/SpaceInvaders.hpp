#ifndef SPACE_INVADERS_HPP
#define SPACE_INVADERS_HPP

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include "Resources.hpp"

#include "systems/CollisionSystem.hpp"
#include "systems/ScoreSystem.hpp"

#include "views/ScoreView.hpp"
#include "views/LevelView.hpp"

#include "models/LaserCannon.hpp"
#include "views/LaserCannonGuiView.hpp"
#include "controllers/LaserCannonController.hpp"

#include "models/Alien.hpp"
#include "views/AlienGuiView.hpp"
#include "controllers/AlienController.hpp"

#include "models/Bullet.hpp"
#include "views/BulletGuiView.hpp"
#include "controllers/BulletController.hpp"

#include "models/Bunker.hpp"
#include "views/BunkerGuiView.hpp"

#include "models/Spaceship.hpp"
#include "controllers/SpaceshipController.hpp"
#include "views/SpaceshipGuiView.hpp"

struct BulletInfo {
	BulletController controller;
	BulletGuiView view;
};

struct SpaceshipInfo {
	SpaceshipController controller;
	SpaceshipGuiView view;
};

struct AlienInfo {
	AlienController controller;
	AlienGuiView view;
};

struct BunkerInfo {
	Bunker model;
	BunkerGuiView view;
};

class SpaceInvaders {
	public:
		SpaceInvaders();
		~SpaceInvaders();


		void update(double dt);
		void render(sf::RenderWindow& window, double dt);

		void moveLeft(double dt);
		void moveRight(double dt);

		void shoot();

	private:
		void alienShoot();

		Resources loadResources();
		void loadAliens(double speed);

		SpaceshipInfo loadSpaceshipInfo();

		unsigned int aliveAliens() const;

		double timer;
		unsigned int level;

		Resources resources;

		LaserCannon laserCannon;
		LaserCannonController laserCannonController;
		LaserCannonGuiView laserCannonView;

		ScoreView scoreView;
		LevelView levelView;

		CollisionSystem collisions;
		ScoreSystem score;

		SpaceshipInfo spaceshipInfo;
		
		std::vector< std::unique_ptr<BulletInfo> > bullets;
		std::vector< std::vector< std::unique_ptr<AlienInfo>  >  > aliens;
		std::vector< std::unique_ptr<BunkerInfo> > bunkers;

		sf::Clock spaceshipClock;

};

#endif

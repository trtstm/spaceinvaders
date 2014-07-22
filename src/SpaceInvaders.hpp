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
#include "views/LivesView.hpp"

#include "models/LaserCannon.hpp"
#include "views/LaserCannonGuiView.hpp"
#include "controllers/LaserCannonController.hpp"

#include "models/Alien.hpp"
#include "views/AlienGuiView.hpp"
#include "controllers/AlienController.hpp"

#include "models/Bullet.hpp"
#include "views/BulletGuiView.hpp"
#include "controllers/BulletController.hpp"

#include "models/BunkerLeft.hpp"
#include "views/BunkerLeftGuiView.hpp"
#include "models/BunkerMiddle.hpp"
#include "views/BunkerMiddleGuiView.hpp"
#include "models/BunkerRight.hpp"
#include "views/BunkerRightGuiView.hpp"

#include "models/Spaceship.hpp"
#include "controllers/SpaceshipController.hpp"
#include "views/SpaceshipGuiView.hpp"

#include "factories/DefaultEntityFactory.hpp"

#include "config/GlobalLoader.hpp"

struct BulletInfo {
	Controller::BulletController controller;
	View::BulletGuiView view;
};

struct SpaceshipInfo {
	Controller::SpaceshipController controller;
	View::SpaceshipGuiView view;
};

struct AlienInfo {
	Controller::AlienController controller;
	View::AlienGuiView view;
};

struct BunkerInfo {
	std::unique_ptr<Model::BunkerLeft> modelLeft;
	View::BunkerLeftGuiView viewLeft;

	std::unique_ptr<Model::BunkerMiddle> modelMiddle;
	View::BunkerMiddleGuiView viewMiddle;

	std::unique_ptr<Model::BunkerRight> modelRight;
	View::BunkerRightGuiView viewRight;
};

enum State { PLAYING, PAUSE, GAMEOVER };

class SpaceInvaders {
	public:
		/**
		* @param factory The factory to use.
		*/
		SpaceInvaders(GlobalLoader globalConfig, std::shared_ptr<Factory::EntityFactory> factory = std::make_shared<Factory::DefaultEntityFactory>());
		~SpaceInvaders();

		/**
		* Iterate the game once.
		*
		* @param dt The delta time.
		*/
		void update(double dt);

		/**
		* Render the game
		*
		* @param window The window to render to.
		* @param dt The delta time.
		*/
		void render(sf::RenderWindow& window, double dt);

		/**
		* Move the lasercannon left.
		*
		* @param dt The delta time.
		*/
		void moveLeft(double dt);

		/**
		* Move the lasercannon right.
		*
		* @param dt The delta time.
		*/
		void moveRight(double dt);

		/**
		* Let the lasercannon shoot.
		*/
		void shoot(Model::LaserCannon* owner);

		/**
		* Checks if the game has ended.
		*
		* @return True if game has ended, false otherwise.
		*/
		bool shouldStop() const;

	private:
		BunkerInfo* newBunkerInfo(const Coordinate position) const;

		void alienShoot();

		Resources loadResources();
		void loadAliens(double speed);

		SpaceshipInfo loadSpaceshipInfo();

		unsigned int aliveAliens() const;

		State state;

		std::shared_ptr<Factory::EntityFactory> factory;

		double timer;
		unsigned int level;

		Resources resources;

		Model::LaserCannon* player1;
		std::unique_ptr<Controller::LaserCannonController> player1Controller;
		std::unique_ptr<View::LaserCannonGuiView> player1View;

		Model::LaserCannon* player2;
		std::unique_ptr<Controller::LaserCannonController> player2Controller;
		std::unique_ptr<View::LaserCannonGuiView> player2View;

		View::ScoreView scoreView;
		View::LevelView levelView;
		View::LivesView livesView;

		System::CollisionSystem collisions;
		System::ScoreSystem score;

		SpaceshipInfo spaceshipInfo;
		
		std::map<int, std::unique_ptr<BulletInfo> > laserCannonBullet;
		std::vector< std::unique_ptr<BulletInfo> > alienBullets;
		std::vector< std::vector< std::unique_ptr<AlienInfo>  >  > aliens;
		std::vector< std::unique_ptr<BunkerInfo> > bunkers;

		sf::Clock spaceshipClock;

		GlobalLoader globalConfig;

};

#endif

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

#include "controllers/MenuController.hpp"
#include "views/MenuView.hpp"

#include "config/GlobalLoader.hpp"
#include "config/LevelLoader.hpp"
#include "config/HighscoreLoader.hpp"

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

enum State { PLAYING, PAUSE, GAMEOVER, MENU };

class SpaceInvaders {
	public:
		/**
		* @param globalConfig config to use.
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
		* Checks if the game has ended.
		*
		* @return True if game has ended, false otherwise.
		*/
		bool shouldStop() const;

		/**
		* Set the state of the game, e.g pause, ...
		*
		* @param newState The state to set.
		*/
		void setState(State newState);

		/**
		* Get the state of the game.
		*
		* @return The state.
		*/
		State getState() const;

		/**
		* Handle an input event.
		*
		* @param event The event
		*/
		void event(sf::Event event);

		/**
		* Initialize a game for 'players' players.
		*
		* @param players The number of players. Only 1,2 are supported.
		*/
		void initGame(int players);

	private:
		friend Controller::LaserCannonController;

		/**
		* Called by LaserCannonController to spawn bullets.
		*
		* @param owner The owner of the bullet
		*/
		void shoot(Model::LaserCannon* owner);

		void gameOver();

		BunkerInfo* newBunkerInfo(const Coordinate position) const;

		void loadAliens();

		void alienShoot();

		SpaceshipInfo loadSpaceshipInfo();

		Resources loadResources();

		unsigned int aliveAliens() const;

		/**********************/

		GlobalLoader globalConfig;
		std::vector<LevelLoader> levels;

		HighscoreLoader highscores;

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

		std::unique_ptr<Controller::MenuController> menuController;
		std::unique_ptr<View::MenuView> menuView;

		sf::Clock spaceshipClock;
};

#endif

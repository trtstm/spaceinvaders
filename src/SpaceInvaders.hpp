#ifndef SPACE_INVADERS_HPP
#define SPACE_INVADERS_HPP

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Resources.hpp"

#include "systems/CollisionSystem.hpp"
#include "systems/ScoreSystem.hpp"

#include "views/ScoreView.hpp"

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

#include "models/Bunker.hpp"
#include "views/BunkerGuiView.hpp"

struct BulletInfo {
	BulletController controller;
	BulletGuiView view;
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

		Resources resources;

		CollisionSystem collisions;
		ScoreSystem score;

		ScoreView scoreView;

		Spaceship spaceship;
		SpaceshipController spaceshipController;
		SpaceshipGuiView spaceshipView;
		
		std::vector< std::unique_ptr<BulletInfo> > bullets;
		std::vector< std::vector< std::unique_ptr<AlienInfo>  >  > aliens;
		std::vector< std::unique_ptr<BunkerInfo> > bunkers;

		double timer;
};

#endif

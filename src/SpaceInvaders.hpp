#ifndef SPACE_INVADERS_HPP
#define SPACE_INVADERS_HPP

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Resources.hpp"

#include "systems/CollisionSystem.hpp"

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

struct BulletInfo {
	BulletController controller;
	BulletGuiView view;
};

struct AlienInfo {
	AlienController controller;
	AlienGuiView view;
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
		Resources resources;

		CollisionSystem collisions;

		Spaceship spaceship;
		SpaceshipController spaceshipController;
		SpaceshipGuiView spaceshipView;
		
		std::vector< std::unique_ptr<BulletInfo> > bullets;
		std::vector< std::unique_ptr<AlienInfo> > aliens;

		double timer;
};

#endif

#ifndef SPACE_INVADERS_HPP
#define SPACE_INVADERS_HPP

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "systems/CollisionSystem.hpp"

#include "controllers/SpaceshipController.hpp"
#include "views/SpaceshipGuiView.hpp"

#include "models/Bullet.hpp"
#include "controllers/BulletController.hpp"
#include "views/BulletGuiView.hpp"

struct BulletInfo {
	std::shared_ptr<Bullet> model;
	std::shared_ptr<BulletController> controller;
	std::shared_ptr<BulletGuiView> view;
};

class SpaceInvaders {
	public:
		SpaceInvaders();

		void update(double dt);
		void render(sf::RenderWindow& window);

		void moveLeft(double dt);
		void moveRight(double dt);

		void shoot();


	private:
		std::shared_ptr<CollisionSystem> collisions;

		std::shared_ptr<Spaceship> spaceship;
		std::shared_ptr<SpaceshipController> spaceshipController;
		std::shared_ptr<SpaceshipGuiView> spaceshipView;
		
		std::vector<BulletInfo> bullets;
};

#endif

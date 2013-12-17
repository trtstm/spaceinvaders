#ifndef SPACE_INVADERS_HPP
#define SPACE_INVADERS_HPP

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

class CollisionSystem;

class Spaceship;
class Alien;
class Bullet;

class SpaceshipController;
class AlienController;
class BulletController;

class SpaceshipGuiView;
class AlienGuiView;
class BulletGuiView;

struct BulletInfo {
	std::shared_ptr<Bullet> model;
	std::shared_ptr<BulletController> controller;
	std::shared_ptr<BulletGuiView> view;
};

struct AlienInfo {
	std::shared_ptr<Alien> model;
	std::shared_ptr<AlienController> controller;
	std::shared_ptr<AlienGuiView> view;
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
		std::vector<AlienInfo> aliens;
};

#endif

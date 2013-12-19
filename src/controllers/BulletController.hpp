#ifndef BULLET_CONTROLLER_HPP
#define BULLET_CONTROLLER_HPP

#include <memory>

#include "models/Bullet.hpp"

class BulletController {
	public:
		BulletController(Bullet bullet);

		void update(double dt);

		Coordinate getPosition() const;

		sf::Rect<double> getCollisionRectangle() const;

		Bullet& getBullet();

	private:
		Bullet bullet;
		
};

#endif

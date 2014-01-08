#ifndef BULLET_CONTROLLER_HPP
#define BULLET_CONTROLLER_HPP

#include <memory>

#include "models/Bullet.hpp"

namespace Controller {

class BulletController {
	public:
		BulletController(Model::Bullet bullet);

		void update(double dt);

		Coordinate getPosition() const;

		sf::Rect<double> getCollisionRectangle() const;

		bool isAlive() const;

		Model::Bullet& getBullet();

	private:
		Model::Bullet bullet;
		
};

}

#endif

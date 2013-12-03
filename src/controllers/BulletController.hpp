#ifndef BULLET_CONTROLLER_HPP
#define BULLET_CONTROLLER_HPP

#include <memory>

#include "models/Bullet.hpp"

class BulletController {
	public:
		BulletController(std::shared_ptr<Bullet> bullet);

		void update(double dt);

	private:
		std::shared_ptr<Bullet> bullet;
		
};

#endif

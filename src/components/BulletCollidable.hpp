#ifndef BULLET_COLLIDABLE_HPP
#define BULLET_COLLIDABLE_HPP

#include <memory>

#include "Collidable.hpp"
#include "Coordinate.hpp"
#include "models/Entity.hpp"

class BulletCollidable : public Collidable {
	public:
		BulletCollidable(int entity);

		void checkCollision(std::shared_ptr<Entity> subject);

	private:
};

#endif

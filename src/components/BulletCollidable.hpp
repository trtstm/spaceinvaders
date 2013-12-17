#ifndef BULLET_COLLIDABLE_HPP
#define BULLET_COLLIDABLE_HPP

#include <memory>

#include "Collidable.hpp"
#include "Coordinate.hpp"
#include "models/Entity.hpp"

class BulletCollidable : public Collidable {
	public:
		BulletCollidable(int entity, int bulletOwner, sf::Rect<double> rect);

		void onCollision(int subject);

	private:
		int bulletOwner;
};

#endif

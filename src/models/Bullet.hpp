#ifndef BULLET_H 
#define BULLET_H

#include "Entity.hpp"
#include "Coordinate.hpp"

#include "components/Movable.hpp"
#include "components/BulletCollidable.hpp"
#include "components/Livable.hpp"

class Bullet : public Entity {
	public:
		Bullet(Coordinate location = Coordinate(0, 0), double speed = 1.0, int owner = -1);
		~Bullet();

		int getOwner() const;

		Movable& getMovable();
		Collidable& getCollidable();
		Livable& getLivable();

	private:
		Movable movable;
		BulletCollidable collidable;
		Livable livable;

		int owner;
};

#endif

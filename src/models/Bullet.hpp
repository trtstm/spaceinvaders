#ifndef BULLET_H 
#define BULLET_H

#include "Entity.hpp"
#include "Coordinate.hpp"

class Bullet : public Entity {
	public:
		Bullet(Coordinate position = Coordinate(0, 0), double speed = 0.0, int owner = -1);
		~Bullet();

		void onCollision(int collidee);

		int getOwner() const;

	private:
		int owner;
};

#endif

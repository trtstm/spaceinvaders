#ifndef BULLET_H 
#define BULLET_H

#include "Entity.hpp"
#include "Coordinate.hpp"

class Bullet : public Entity {
	public:
		Bullet(Coordinate location, double speed, int owner);
		~Bullet();

		int getOwner() const;

	private:
		int owner;
};

#endif

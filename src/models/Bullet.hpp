#ifndef BULLET_H 
#define BULLET_H

#include "Entity.hpp"
#include "Coordinate.hpp"

namespace Model {

class Bullet : public Entity {
	public:
		/**
		* @param position The position.
		* @param speed The speed.
		* @param owner Who shot the bullet.
		*/
		Bullet(Coordinate position = Coordinate(0, 0), double speed = 0.0, int owner = -1);
		~Bullet();

		/**
		* Called when another entity has collided with us.
		*
		* @param entity The entity that collided with us.
		*/
		void onCollision(const Entity* entity);

		/**
		* Get the owner of the bullet.
		*
		* @return The owner.
		*/
		int getOwner() const;

	private:
		int owner;
};

}

#endif

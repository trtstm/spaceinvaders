#ifndef BULLET_H 
#define BULLET_H

#include "Entity.hpp"
#include "Coordinate.hpp"

namespace Model {

class Bullet : public Entity {
	public:
		enum Type {FRIENDLY, ENEMY};

		/**
		* @param position The position.
		* @param speed The speed.
		* @param owner Who shot the bullet.
		*/
		Bullet(Coordinate position, double speed, Type type, int owner);
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

		Type getType() const;

	private:
		Type type;
		int owner;
};

}

#endif

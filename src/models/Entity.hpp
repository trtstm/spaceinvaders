#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <SFML/Graphics/Rect.hpp>

#include "Subject.hpp"
#include "Coordinate.hpp"

namespace Model {

enum EntityType { BULLET, LASERCANNON, ALIEN, SPACESHIP, BUNKER };

class Entity : public Subject {
	public:
		/**
		* @param type The entity type.
		* @param health The health.
		* @param position The position.
		* @param speed The speed.
		* @param collisionRectangle The collision rectangle.
		*/
		Entity(EntityType type, int health, Coordinate position, double speed, sf::Rect<double> collisionRectangle);
		virtual ~Entity();

		/**
		* Get the id of the entity.
		*
		* @return The id.
		*/
		int getId() const;

		/**
		* Move left.
		*
		* @param dt The delta time.
		*/
		virtual void moveLeft(double dt);

		/**
		* Move right.
		*
		* @param dt The delta time.
		*/
		virtual void moveRight(double dt);

		/**
		* Move up.
		*
		* @param dt The delta time.
		*/
		virtual void moveUp(double dt);

		/**
		* Move down.
		*
		* @param dt The delta time.
		*/
		virtual void moveDown(double dt);

		/**
		* Set the position.
		*
		* @param newPosition The position.
		*/
		void setPosition(Coordinate newPosition);

		/**
		* Do damage to the entity.
		*
		* @param damage The damage.
		*/
		void doDamage(int damage);
		
		/**
		* Get the collision rectangle.
		*
		* @return The collision rectangle.
		*/
		sf::Rect<double> getCollisionRectangle() const;

		/**
		* Get the entity type.
		*
		* @return The entity type.
		*/
		EntityType getType() const;

		/**
		* Set the health.
		*
		* @param health The health.
		*/
		void setHealth(int health);

		/**
		* Get the health.
		*
		* @return The health of the entity.
		*/
		int getHealth() const;

		/**
		* Check if entity is alive.
		*
		* @return True if entity is alive, otherwise false.
		*/
		bool isAlive() const;

		/**
		* Get the position.
		*
		* @return The position.
		*/
		Coordinate getPosition() const;

		/**
		* Get the speed.
		*
		* @return The speed.
		*/
		double getSpeed() const;

		/**
		* Called when another entity has collided with us.
		*
		* @param entity The entity that collided with us.
		*/
		virtual void onCollision(const Entity* entity);
		
		/**
		* Unregister all observers for this entity.
		*/
		void unRegisterObservers();
		
		bool operator==(const Entity& e) const;
		bool operator!=(const Entity& e) const;
		bool operator<(const Entity& e) const;
		bool operator>(const Entity& e) const;
		bool operator<=(const Entity& e) const;
		bool operator>=(const Entity& e) const;

	protected:

	private:
		static int idCounter;
		int id;

		EntityType type;
		int health;
		Coordinate position;
		double speed;
		sf::Rect<double> collisionRectangle;
};

}

#endif

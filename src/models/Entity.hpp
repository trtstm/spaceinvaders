#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <SFML/Graphics/Rect.hpp>

#include "Subject.hpp"
#include "Coordinate.hpp"

class Component;

class Entity : public Subject {
	public:
		Entity(int health, Coordinate position, double speed, sf::Rect<double> collisionRectangle);
		virtual ~Entity() ;

		int getId() const;

		virtual void moveLeft(double dt);
		virtual void moveRight(double dt);
		virtual void moveUp(double dt);
		virtual void moveDown(double dt);
		void setPosition(Coordinate newPosition);

		void doDamage(int damage);
		
		sf::Rect<double> getCollisionRectangle() const;

		int getHealth() const;
		Coordinate getPosition() const;
		double getSpeed() const;

		virtual void onCollision(int collidee);
		

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

		int health;
		Coordinate position;
		double speed;
		sf::Rect<double> collisionRectangle;
		

		std::map< std::string, std::shared_ptr<Component> > components;
};

#endif

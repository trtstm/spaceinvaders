#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <typeinfo>

#include "components/Movable.hpp"
#include "components/Collidable.hpp"
#include "components/Livable.hpp"

class Component;

class Entity {
	public:
		Entity(std::shared_ptr<Movable> movable, std::shared_ptr<Collidable> collidable, std::shared_ptr<Livable> livable);
		virtual ~Entity() ;

		Movable& getMovable();
		Collidable& getCollidable();
		Livable& getLivable();

		int getId() const;

		void moveLeft(double dt);
		void moveRight(double dt);
		void moveUp(double dt);
		void moveDown(double dt);

		void unRegisterObservers();
		
		bool operator==(const Entity& e) const;
		bool operator!=(const Entity& e) const;
		bool operator<(const Entity& e) const;
		bool operator>(const Entity& e) const;
		bool operator<=(const Entity& e) const;
		bool operator>=(const Entity& e) const;

	protected:
		std::shared_ptr<Movable> movable;		
		std::shared_ptr<Collidable> collidable;		
		std::shared_ptr<Livable> livable;		

		static int idCounter;
	private:
		const int id;

		std::map< std::string, std::shared_ptr<Component> > components;
};

#endif

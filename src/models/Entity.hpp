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
		Entity();
		virtual ~Entity() ;

		virtual Movable& getMovable() = 0;
		virtual Collidable& getCollidable() = 0;
		virtual Livable& getLivable() = 0;

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
		static int idCounter;
		int id;
	private:


		std::map< std::string, std::shared_ptr<Component> > components;
};

#endif

#ifndef COLLISION_SYSTEM_HPP
#define COLLISION_SYSTEM_HPP

#include <map>

#include "Observer.hpp"
#include "models/Entity.hpp"
#include "models/Bullet.hpp"
#include "models/Alien.hpp"
#include "models/Spaceship.hpp"
#include "models/LaserCannon.hpp"

namespace System {

class CollisionSystem : public Observer {
	public:
		~CollisionSystem();

		/**
		* Add an entity that should be checked for collisions.
		*
		* @param entity The entity to add.
		* @param registerMove If the system should register for move messages.
		*/
		void addEntity(Model::Entity& entity, bool registerMove = false);

		/**
		* Remove an entity.
		*
		* @param entity The entity to remove.
		*/
		void removeEntity(Model::Entity& entity);

		/**
		* Notify the system that something happend.
		*
		* @param msg The message.
		* @return False if the subject should remove us from the observer list, else true.
		*/
		bool notify(Message::Message& msg);

	private:
		bool hasCollision(Model::Entity* sender, Model::Entity* subject);

		Model::Entity* findEntity(int id);

		std::map< int, Model::Bullet* > bullets;
		std::map< int, Model::Alien* > aliens;
		std::map< int, Model::Spaceship* > spaceships;
		std::map< int, Model::LaserCannon* > laserCannons;
		std::map< int, Model::Entity* > bunkers;

		std::map< int, Model::Entity* > rest;
};

}

#endif

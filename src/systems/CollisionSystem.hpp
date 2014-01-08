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

		void addEntity(Model::Entity& entity, bool registerMove = false);
		void removeEntity(Model::Entity& entity);

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

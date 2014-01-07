#ifndef COLLISION_SYSTEM_HPP
#define COLLISION_SYSTEM_HPP

#include <map>

#include "Observer.hpp"
#include "models/Entity.hpp"
#include "models/Bullet.hpp"
#include "models/Alien.hpp"
#include "models/Spaceship.hpp"
#include "models/LaserCannon.hpp"

class CollisionSystem : public Observer {
	public:
		~CollisionSystem();

		void addEntity(Entity& entity, bool registerMove = false);
		void removeEntity(Entity& entity);

		bool notify(Message& msg);

	private:
		bool hasCollision(Entity* sender, Entity* subject);

		Entity* findEntity(int id);

		std::map< int, Bullet* > bullets;
		std::map< int, Alien* > aliens;
		std::map< int, Spaceship* > spaceships;
		std::map< int, LaserCannon* > laserCannons;
		std::map< int, Entity* > bunkers;

		std::map< int, Entity* > rest;
};

#endif

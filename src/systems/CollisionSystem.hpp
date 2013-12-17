#ifndef COLLISION_SYSTEM_HPP
#define COLLISION_SYSTEM_HPP

#include <map>

#include "Observer.hpp"
#include "models/Entity.hpp"

class CollisionSystem : public Observer {
	public:
		void addEntity(std::shared_ptr<Entity> entity);
		void removeEntity(int entity);

		bool notify(Message& msg);

	private:
		std::map< int, std::shared_ptr<Entity> > entities;
};

#endif

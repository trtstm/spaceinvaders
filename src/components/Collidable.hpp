#ifndef COLLIDABLE_HPP
#define COLLIDABLE_HPP

#include <memory>

#include "Component.hpp"
#include "Coordinate.hpp"
#include "models/Entity.hpp"

class Collidable : public Component {
	public:
		Collidable(int entity);

		virtual void checkCollision(std::shared_ptr<Entity> subject);

	private:
};

#endif

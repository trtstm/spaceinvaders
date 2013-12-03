#ifndef COLLIDABLE_HPP
#define COLLIDABLE_HPP

#include <memory>

#include "Component.hpp"
#include "Coordinate.hpp"
#include "models/Entity.hpp"

class Collidable : public Component {
	public:
		Collidable(std::shared_ptr<Entity> entity);

		void onCollision();

	private:
};

#endif

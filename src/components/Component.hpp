#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <memory>

#include "Subject.hpp"
#include "models/Entity.hpp"

enum ComponentType {MOVABLE, COLLIDABLE, LIVABLE};

class Component : public Subject {
	public:
		Component(ComponentType type, std::shared_ptr<Entity> entity);
		virtual ~Component() = 0;
	
		ComponentType getType() const;

		std::shared_ptr<Entity> getEntity();

	private:
		ComponentType type;
		std::shared_ptr<Entity> entity;
};

#endif

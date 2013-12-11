#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <memory>

#include "Subject.hpp"

enum ComponentType {MOVABLE, COLLIDABLE, LIVABLE};

class Component : public Subject {
	public:
		Component(ComponentType type, int entity);
		virtual ~Component() = 0;

	protected:
		ComponentType type;
		int entity;
};

#endif

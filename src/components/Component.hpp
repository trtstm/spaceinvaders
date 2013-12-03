#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Subject.hpp"

enum ComponentType {MOVABLE};

class Component : public Subject {
	public:
		Component(ComponentType type);
		virtual ~Component() = 0;
	
		ComponentType getType() const;

	private:
		ComponentType type;
};

#endif

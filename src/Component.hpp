#ifndef COMPONENT_HPP
#define COMPONENT_HPP

enum ComponentType {MOVEABLE};

class Component {
	public:
		Component(ComponentType type);
		virtual ~Component() = 0;
	
		ComponentType getType() const;

	private:
		ComponentType type;
};

#endif

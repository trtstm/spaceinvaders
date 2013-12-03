#include "Component.hpp"

Component::Component(ComponentType type)
	: type(type)
{
}

Component::~Component()
{
}

ComponentType Component::getType() const
{
	return type;
}

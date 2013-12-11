#include "Component.hpp"

Component::Component(ComponentType type, int entity)
	: type(type), entity(entity)
{
}

Component::~Component()
{
}

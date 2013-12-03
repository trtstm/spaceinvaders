#include "Component.hpp"

Component::Component(ComponentType type, std::shared_ptr<Entity> entity)
	: type(type), entity(entity)
{
}

Component::~Component()
{
}

ComponentType Component::getType() const
{
	return type;
}

std::shared_ptr<Entity> Component::getEntity()
{
	return entity;
}

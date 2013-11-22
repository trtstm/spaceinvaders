#include "Entity.hpp"
#include "Component.hpp"

Entity::~Entity()
{
}

void Entity::setComponent(const std::string& name, Component* component)
{
	components.erase(name);
	components[name] = std::unique_ptr<Component>(component);
}

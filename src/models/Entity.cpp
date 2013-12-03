#include <iostream>

#include "Entity.hpp"

int Entity::idCounter = 0;

Entity::Entity()
	: id(idCounter)
{
	idCounter++;
}

Entity::~Entity()
{
}

int Entity::getId() const
{
	return id;
}

bool Entity::operator==(const Entity& e) const
{
	return id == e.id;
}

bool Entity::operator!=(const Entity& e) const
{
	return !(*this == e);
}

bool Entity::operator<(const Entity& e) const
{
	return id < e.id;
}

bool Entity::operator>(const Entity& e) const
{
	return id > e.id;
}

bool Entity::operator<=(const Entity& e) const
{
	return id <= e.id;
}

bool Entity::operator>=(const Entity& e) const
{
	return id >= e.id;
}

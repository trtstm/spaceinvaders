#include <iostream>

#include "Entity.hpp"

int Entity::idCounter = 0;

Entity::Entity(std::shared_ptr<Movable> movable)
	: movable(movable), id(idCounter)
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

void Entity::moveLeft(double dt)
{
	movable->moveLeft(dt);
}

void Entity::moveRight(double dt)
{
	movable->moveRight(dt);
}

void Entity::moveUp(double dt)
{
	movable->moveUp(dt);
}

void Entity::moveDown(double dt)
{
	movable->moveDown(dt);
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

template <>
Movable* Entity::getComponent()
{
	return movable.get();
}

template <>
void Entity::setComponent(std::shared_ptr<Movable> component)
{
	throw "Could not set movable.";
}

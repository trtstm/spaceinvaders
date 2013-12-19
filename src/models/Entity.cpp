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

void Entity::moveLeft(double dt)
{
	getMovable().moveLeft(dt);
}

void Entity::moveRight(double dt)
{
	getMovable().moveRight(dt);
}

void Entity::moveUp(double dt)
{
	std::cout << "!" << std::endl;
	getMovable().moveUp(dt);
	std::cout << "!" << std::endl;
}

void Entity::moveDown(double dt)
{
	getMovable().moveDown(dt);
}

void Entity::unRegisterObservers()
{
	getMovable().unRegisterAll();
	getCollidable().unRegisterAll();
	getLivable().unRegisterAll();
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

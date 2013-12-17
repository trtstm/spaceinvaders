#include <iostream>

#include "Entity.hpp"

#include "components/Movable.hpp"
#include "components/Collidable.hpp"
#include "components/Livable.hpp"

int Entity::idCounter = 0;

Entity::Entity(std::shared_ptr<Movable> movable, std::shared_ptr<Collidable> collidable, std::shared_ptr<Livable> livable)
	: movable(movable), collidable(collidable), livable(livable), id(idCounter)
{
	idCounter++;
}

Entity::~Entity()
{
}

Movable& Entity::getMovable()
{
	return *movable.get();
}

Collidable& Entity::getCollidable()
{
	return *collidable.get();
}

Livable& Entity::getLivable()
{
	return *livable.get();
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

void Entity::unRegisterObservers()
{
	movable->unRegisterAll();
	collidable->unRegisterAll();
	livable->unRegisterAll();
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

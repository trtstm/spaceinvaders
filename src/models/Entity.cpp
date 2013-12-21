#include <iostream>

#include "Entity.hpp"

#include "messages/MoveMessage.hpp"
#include "messages/DiedMessage.hpp"

int Entity::idCounter = 0;

Entity::Entity(int health, Coordinate position, double speed, sf::Rect<double> collisionRectangle)
	: id(idCounter), health(health), position(position), speed(speed), collisionRectangle(collisionRectangle)
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
	auto newPosition = position;
	newPosition.x -= speed * dt;
	setPosition(newPosition);
}

void Entity::moveRight(double dt)
{
	auto newPosition = position;
	newPosition.x += speed * dt;
	setPosition(newPosition);
}

void Entity::moveUp(double dt)
{
	auto newPosition = position;
	newPosition.y -= speed * dt;
	setPosition(newPosition);
}

void Entity::moveDown(double dt)
{
	auto newPosition = position;
	newPosition.y += speed * dt;
	setPosition(newPosition);
}

void Entity::setPosition(Coordinate newPosition)
{
	MoveMessage msg(id, position, newPosition);
	
	position = newPosition;

	notifyMove(msg);
}


void Entity::doDamage(int damage)
{
	health -= damage;

	if(health <= 0) {
		DiedMessage msg(getId());

		notifyDied(msg);
	}
}

sf::Rect<double> Entity::getCollisionRectangle() const
{
	return collisionRectangle;
}

int Entity::getHealth() const
{
	return health;
}

Coordinate Entity::getPosition() const
{
	return position;
}

double Entity::getSpeed() const
{
	return speed;
}

void Entity::onCollision(int collidee)
{
}

void Entity::unRegisterObservers()
{
	unRegisterAll();
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

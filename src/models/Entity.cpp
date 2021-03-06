#include <iostream>

#include "Entity.hpp"

#include "messages/MoveMessage.hpp"
#include "messages/DiedMessage.hpp"

namespace Model {

int Entity::idCounter = 0;

Entity::Entity(EntityType type, int health, Coordinate position, double speed, sf::Rect<double> collisionRectangle)
	: id(idCounter), type(type), health(health), position(position), speed(speed), collisionRectangle(collisionRectangle)
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
	Message::MoveMessage msg(id, position, newPosition);
	
	position = newPosition;

	notifyMove(msg);
}


void Entity::doDamage(int damage)
{
	health -= damage;

	if(health <= 0) {
		onDied();
	}
}

sf::Rect<double> Entity::getCollisionRectangle() const
{
	return collisionRectangle;
}

EntityType Entity::getType() const
{
	return type;
}

void Entity::setHealth(int health)
{
	this->health = health;
}

bool Entity::isAlive() const
{
	return (health > 0);
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

void Entity::onCollision(const Entity* entity)
{
	(void)entity;
}

void Entity::onDied()
{
	Message::DiedMessage msg(getId());

	notifyDied(msg);
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

}

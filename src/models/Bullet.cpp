#include <iostream>
#include <memory>

#include "Bullet.hpp"

Bullet::Bullet(Coordinate location, double speed, int owner)
	: Entity(), 
		movable(id, location, speed), 
		collidable(id, owner, sf::Rect<double>(0.0, 0.0, 4.0, 10.0)),
		livable(id, 1),
		owner(owner)
{
}

Bullet::~Bullet()
{
}

int Bullet::getOwner() const
{
	return owner;
}

Movable& Bullet::getMovable()
{
	return movable;
}

Collidable& Bullet::getCollidable()
{
	return collidable;
}

Livable& Bullet::getLivable()
{
	return livable;
}

#include <iostream>

#include "Bullet.hpp"

Bullet::Bullet(Coordinate position, int owner)
	: Entity(1, position, 300, sf::Rect<double>(0.0, 0.0, 4.0, 10.0)), owner(owner)
{
}

Bullet::~Bullet()
{
}

int Bullet::getOwner() const
{
	return owner;
}

#include <iostream>
#include <memory>

#include "Bullet.hpp"

Bullet::Bullet(Coordinate location, double speed, int owner)
	: Entity(std::make_shared<Movable>(idCounter, location, speed)), owner(owner)
{
}

Bullet::~Bullet()
{
	std::cout << "Deleted bullet" << std::endl;
}

int Bullet::getOwner() const
{
	return owner;
}

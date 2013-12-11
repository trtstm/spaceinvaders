#include <iostream>
#include <memory>

#include "Bullet.hpp"

Bullet::Bullet(Coordinate location, double speed)
	: Entity(std::make_shared<Movable>(idCounter, location, speed))
{
}

Bullet::~Bullet()
{
	std::cout << "Deleted bullet" << std::endl;
}

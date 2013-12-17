#include <iostream>
#include <memory>

#include "Bullet.hpp"

#include "components/BulletCollidable.hpp"

Bullet::Bullet(Coordinate location, double speed, int owner)
	: Entity(std::make_shared<Movable>(idCounter, location, speed),
			std::make_shared<BulletCollidable>(idCounter, owner, sf::Rect<double>(0.0, 0.0, 4.0, 10.0)),
			std::make_shared<Livable>(idCounter, 1)),
			owner(owner)
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

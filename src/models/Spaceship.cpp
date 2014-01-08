#include "Spaceship.hpp"

#include "Bullet.hpp"

namespace Model {

Spaceship::Spaceship(Coordinate position, double speed)
	: Entity(SPACESHIP, 1, position, speed, sf::Rect<double>(0.0, 0.0, 48.0, 21.0))
{
}

Spaceship::~Spaceship()
{
}

void Spaceship::onCollision(const Entity* entity)
{
	if(entity->getType() == BULLET) {
		//auto bullet = static_cast<const Bullet*>(entity);

		this->doDamage(1);
	}
}

}

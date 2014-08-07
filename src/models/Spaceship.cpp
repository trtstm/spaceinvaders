#include "Spaceship.hpp"

#include "Bullet.hpp"

#include "messages/ScoreMessage.hpp"

namespace Model {

Spaceship::Spaceship(Coordinate position, double speed, int score, double width, double height)
	: Entity(SPACESHIP, 1, position, speed, sf::Rect<double>(0.0, 0.0, width, height)), score(score)
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

void Spaceship::onDied()
{
	Entity::onDied();

	Message::ScoreMessage msg(getId(), score);
	notifyScore(msg);
}

}

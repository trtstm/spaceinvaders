#include "Alien.hpp"

#include "Bullet.hpp"
#include "messages/ScoreMessage.hpp"

namespace Model {

Alien::Alien(Coordinate position, double speed, int score, double width, double height)
	: Entity(ALIEN, 1, position, speed, sf::Rect<double>(0.0, 0.0, width, height)), score(score)
{
}

Alien::~Alien()
{
}

void Alien::moveDown(double dt)
{
	auto newPosition = getPosition();
	newPosition.y += 16 * dt;

	setPosition(newPosition);
}

void Alien::onCollision(const Entity* entity)
{
	if(entity->getType() == BULLET) {
		auto bullet = static_cast<const Bullet*>(entity);

		if(bullet->getType() == Bullet::ENEMY) {
			return;
		}
	}

	this->doDamage(1);
}

void Alien::onDied()
{
	Entity::onDied();

	Message::ScoreMessage msg(getId(), score);
	notifyScore(msg);
}

}

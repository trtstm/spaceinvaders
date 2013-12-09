#include "BulletHitMessage.hpp"

BulletHitMessage::BulletHitMessage(std::shared_ptr<Entity> entity, std::shared_ptr<Entity> subject)
	: Message(BULLETHIT, entity), subject(subject)
{
}

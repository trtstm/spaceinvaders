#include "BulletHitMessage.hpp"

BulletHitMessage::BulletHitMessage(int entity, int subject)
	: Message(BULLETHIT, entity), subject(subject)
{
}

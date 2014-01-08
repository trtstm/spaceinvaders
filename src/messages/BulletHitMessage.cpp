#include "BulletHitMessage.hpp"

namespace Message {

BulletHitMessage::BulletHitMessage(int entity, int subject)
	: Message(BULLETHIT, entity), subject(subject)
{
}

}

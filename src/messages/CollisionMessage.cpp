#include "CollisionMessage.hpp"

CollisionMessage::CollisionMessage(int entity)
	: Message(COLLISION, entity)
{
}

#include "CollisionMessage.hpp"

CollisionMessage::CollisionMessage(std::shared_ptr<Entity> entity)
	: Message(COLLISION, entity)
{
}

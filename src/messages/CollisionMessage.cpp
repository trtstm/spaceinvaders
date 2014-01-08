#include "CollisionMessage.hpp"

namespace Message {

CollisionMessage::CollisionMessage(int entity)
	: Message(COLLISION, entity)
{
}

}

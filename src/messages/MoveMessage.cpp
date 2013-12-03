#include "MoveMessage.hpp"

MoveMessage::MoveMessage(std::shared_ptr<Entity> entity, const Coordinate& oldPosition, const Coordinate& newPosition)
	: Message(MOVE, entity), oldPosition(oldPosition), newPosition(newPosition)
{
}

#include "MoveMessage.hpp"

namespace Message {

MoveMessage::MoveMessage(int entity, const Coordinate& oldPosition, const Coordinate& newPosition)
	: Message(MOVE, entity), oldPosition(oldPosition), newPosition(newPosition)
{
}

}

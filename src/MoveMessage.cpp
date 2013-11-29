#include "MoveMessage.hpp"

MoveMessage::MoveMessage(unsigned int sender, const Coordinate& oldPosition, const Coordinate& newPosition)
	: Message(MOVE, sender), oldPosition(oldPosition), newPosition(newPosition)
{
}

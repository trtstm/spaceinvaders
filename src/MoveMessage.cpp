#include "MoveMessage.hpp"

MoveMessage::MoveMessage(unsigned int sender, const Coordinate& oldPos, const Coordinate& newPos)
	: Message(MOVE, sender), oldPos(oldPos), newPos(newPos)
{
}

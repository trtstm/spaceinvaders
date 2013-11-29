#ifndef MOVE_MESSAGE_HPP
#define MOVE_MESSAGE_HPP

#include "Message.hpp"
#include "Coordinate.hpp"

class MoveMessage : public Message {
	public:
		MoveMessage(unsigned int sender, const Coordinate& oldPosition, const Coordinate& newPosition);

		Coordinate oldPosition;
		Coordinate newPosition;
};

#endif

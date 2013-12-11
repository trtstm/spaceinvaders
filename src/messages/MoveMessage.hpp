#ifndef MOVE_MESSAGE_HPP
#define MOVE_MESSAGE_HPP

#include <memory>

#include "Message.hpp"
#include "Coordinate.hpp"
#include "models/Entity.hpp"

class MoveMessage : public Message {
	public:
		MoveMessage(int entity, const Coordinate& oldPosition, const Coordinate& newPosition);

		Coordinate oldPosition;
		Coordinate newPosition;
};

#endif

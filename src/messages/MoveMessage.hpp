#ifndef MOVE_MESSAGE_HPP
#define MOVE_MESSAGE_HPP

#include <memory>

#include "Message.hpp"
#include "Coordinate.hpp"
#include "models/Entity.hpp"

namespace Message {

class MoveMessage : public Message {
	public:
		/**
		@param entity The entity that sends the message.
		@param oldPosition The old position of the entity.
		@param newPosition The new position of the entity.
		*/
		MoveMessage(int entity, const Coordinate& oldPosition, const Coordinate& newPosition);

		Coordinate oldPosition;
		Coordinate newPosition;
};

}

#endif

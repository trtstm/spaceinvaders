#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <memory>

namespace Message {

enum MessageType {MOVE, COLLISION, BULLETHIT, DIED, DELETEENTITY};

class Message {
	public:
		/**
		@param type The type of the message.
		@param entity The entity that sends the message.
		*/
		Message(MessageType type, int entity);
		virtual ~Message() = 0;

		MessageType type;
		int entity;
};

}

#endif

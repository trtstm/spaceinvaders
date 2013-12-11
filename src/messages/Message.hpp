#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <memory>

enum MessageType {MOVE, COLLISION, BULLETHIT, DIED, DELETEENTITY};

class Message {
	public:
		Message(MessageType type, int entity);
		virtual ~Message() = 0;

		MessageType type;
		int entity;
};

#endif

#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <memory>

#include "models/Entity.hpp"

enum MessageType {MOVE, COLLISION, BULLETHIT, DIED, DELETEENTITY};

class Message {
	public:
		Message(MessageType type, std::shared_ptr<Entity> entity);
		virtual ~Message() = 0;

		/**
		* Get the type of the message.
		*
		* @return The message type.
		*/
		MessageType getType() const;

		/**
		* Get the sender of the message.
		*
		* @return The sender's id.
		*/
		std::shared_ptr<Entity> getEntity();

	private:
		MessageType type;
		std::shared_ptr<Entity> entity;
};

#endif

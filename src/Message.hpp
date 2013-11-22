#ifndef MESSAGE_HPP
#define MESSAGE_HPP

enum MessageType {MOVE};

class Message {
	public:
		Message(MessageType type, unsigned int sender);
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
		unsigned int getSender() const;

	private:
		MessageType type;
		unsigned int sender;
};

#endif

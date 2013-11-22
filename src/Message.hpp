#ifndef MESSAGE_HPP
#define MESSAGE_HPP

enum MessageType {MOVE};

class Message {
	public:
		Message(MessageType type);
		virtual ~Message() = 0;

		/**
		* Get the type of the message.
		*
		* @return The message type.
		*/
		MessageType getType() const;

	private:
		MessageType type;
};

#endif

#include "Message.hpp"

Message::Message(MessageType type, unsigned int sender)
	: type(type), sender(sender)
{
}

Message::~Message()
{
}

MessageType Message::getType() const
{
	return type;
}

unsigned int Message::getSender() const
{
	return sender;
}

#include "Message.hpp"

Message::~Message()
{
}

MessageType Message::getType() const
{
	return type;
}

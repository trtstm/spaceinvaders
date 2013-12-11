#include "Message.hpp"

Message::Message(MessageType type, int entity)
	: type(type), entity(entity)
{
}

Message::~Message()
{
}


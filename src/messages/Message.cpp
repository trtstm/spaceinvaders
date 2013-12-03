#include "Message.hpp"

Message::Message(MessageType type, std::shared_ptr<Entity> entity)
	: type(type), entity(entity)
{
}

Message::~Message()
{
}

MessageType Message::getType() const
{
	return type;
}

std::shared_ptr<Entity> Message::getEntity()
{
	return entity;
}

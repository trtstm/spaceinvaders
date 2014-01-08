#include "Message.hpp"

namespace Message {

Message::Message(MessageType type, int entity)
	: type(type), entity(entity)
{
}

Message::~Message()
{
}

}

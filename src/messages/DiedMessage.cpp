#include "DiedMessage.hpp"

DiedMessage::DiedMessage(std::shared_ptr<Entity> entity)
	: Message(DIED, entity)
{
}

#include "DiedMessage.hpp"

namespace Message {

DiedMessage::DiedMessage(int entity)
	: Message(DIED, entity)
{
}

}

#ifndef DIED_MESSAGE_HPP
#define DIED_MESSAGE_HPP

#include <memory>

#include "Message.hpp"
#include "models/Entity.hpp"

namespace Message {

class DiedMessage : public Message {
	public:
		DiedMessage(int entity);
};

}

#endif

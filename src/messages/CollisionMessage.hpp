#ifndef COLLISION_MESSAGE_HPP
#define COLLISION_MESSAGE_HPP

#include <memory>

#include "Message.hpp"
#include "models/Entity.hpp"

namespace Message {

class CollisionMessage : public Message {
	public:
		CollisionMessage(int entity);
};

}

#endif

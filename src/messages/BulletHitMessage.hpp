#ifndef BULLET_HIT_MESSAGE_HPP
#define BULLET_HIT_MESSAGE_HPP

#include <memory>

#include "Message.hpp"
#include "models/Entity.hpp"

namespace Message {

class BulletHitMessage : public Message {
	public:
		/**
		@param entity The entity that sends the message.
		@param subject The entity that got hit.
		*/
		BulletHitMessage(int entity, int subject);

		int subject;
};

}

#endif

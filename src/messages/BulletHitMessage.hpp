#ifndef BULLET_HIT_MESSAGE_HPP
#define BULLET_HIT_MESSAGE_HPP

#include <memory>

#include "Message.hpp"
#include "models/Entity.hpp"

class BulletHitMessage : public Message {
	public:
		BulletHitMessage(int entity, int subject);

		int subject;
};

#endif

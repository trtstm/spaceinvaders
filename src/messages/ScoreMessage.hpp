#ifndef SCORE_MESSAGE_HPP
#define SCORE_MESSAGE_HPP

#include <memory>

#include "Message.hpp"
#include "models/Entity.hpp"

namespace Message {

class ScoreMessage : public Message {
	public:
		/**
		* @param entity The entity that sends the message.
		* @param score The score.
		*/
		ScoreMessage(int entity, int score);

		int score;
};

}

#endif

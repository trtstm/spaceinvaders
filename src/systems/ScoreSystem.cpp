#include "ScoreSystem.hpp"

#include "messages/ScoreMessage.hpp"

namespace System {

ScoreSystem::ScoreSystem()
	: score(0)
{
}


int ScoreSystem::getScore() const
{
	return score;
}

bool ScoreSystem::notify(Message::Message& msg)
{
	switch(msg.type) {
		case Message::SCORE:
		{
			auto& scoreMessage = static_cast<Message::ScoreMessage&>(msg);

			score += scoreMessage.score;

			break;
		}

		default:
			break;
	}

	return true;
}

}

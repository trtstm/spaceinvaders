#include "ScoreSystem.hpp"

#include "messages/DiedMessage.hpp"

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
		case Message::DIED:
		{
			score++;

			break;
		}

		default:
			break;
	}

	return true;
}

}

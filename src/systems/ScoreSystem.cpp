#include "ScoreSystem.hpp"

#include "messages/DiedMessage.hpp"

ScoreSystem::ScoreSystem()
	: score(0)
{
}


int ScoreSystem::getScore() const
{
	return score;
}

bool ScoreSystem::notify(Message& msg)
{
	switch(msg.type) {
		case DIED:
		{
			score++;

			break;
		}

		default:
			break;
	}

	return true;
}

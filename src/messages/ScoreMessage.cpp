#include "ScoreMessage.hpp"

namespace Message {

ScoreMessage::ScoreMessage(int entity, int score)
	: Message(SCORE, entity), score(score)
{
}

}

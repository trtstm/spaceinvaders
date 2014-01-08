#ifndef SCORE_SYSTEM_HPP
#define SCORE_SYSTEM_HPP

#include "Observer.hpp"

namespace System {

class ScoreSystem : public Observer {
	public:
		ScoreSystem();

		int getScore() const;

		bool notify(Message::Message& msg);

	private:
		int score;
};

}

#endif

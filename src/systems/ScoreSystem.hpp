#ifndef SCORE_SYSTEM_HPP
#define SCORE_SYSTEM_HPP

#include "Observer.hpp"

class ScoreSystem : public Observer {
	public:
		ScoreSystem();

		int getScore() const;

		bool notify(Message& msg);

	private:
		int score;
};

#endif

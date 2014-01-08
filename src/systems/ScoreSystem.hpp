#ifndef SCORE_SYSTEM_HPP
#define SCORE_SYSTEM_HPP

#include "Observer.hpp"

namespace System {

class ScoreSystem : public Observer {
	public:
		ScoreSystem();

		/**
		* Get the score.
		*
		* @return The score.
		*/
		int getScore() const;

		/**
		* Notify the system that something happend.
		*
		* @param msg The message.
		*/
		bool notify(Message::Message& msg);

	private:
		int score;
};

}

#endif

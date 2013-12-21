#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <memory>
#include <set>

#include "messages/Message.hpp"
#include "Observer.hpp"

class Subject {
	public:
		virtual ~Subject();

		void registerMove(Observer& observer);
		void unRegisterMove(Observer& observer);

		void registerCollision(Observer& observer);
		void unRegisterCollision(Observer& observer);

		void registerDied(Observer& observer);
		void unRegisterDied(Observer& observer);

		void unRegisterAll();

		void notifyMove(Message& msg);
		void notifyCollision(Message& msg);
		void notifyDied(Message& msg);

	private:
		std::set<Observer*> move;
		std::set<Observer*> collision;
		std::set<Observer*> died;
};

#endif

#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <memory>
#include <set>

#include "messages/Message.hpp"
#include "Observer.hpp"

class Subject {
	public:
		virtual ~Subject();

		void registerObserver(Observer& observer);
		void unRegisterObserver(Observer& observer);

		void unRegisterAll();

		void notifyObservers(Message& msg);

	private:
		std::set<Observer*> observers;
};

#endif

#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <memory>
#include <set>

#include "messages/Message.hpp"
#include "Observer.hpp"

class Subject {
	public:
		virtual ~Subject();

		void registerObserver(std::shared_ptr<Observer> observer);
		void unRegisterObserver(std::shared_ptr<Observer> observer);

		void unRegisterAll();

		void notifyObservers(Message& msg);

	private:
		std::set< std::shared_ptr<Observer> > observers;
};

#endif

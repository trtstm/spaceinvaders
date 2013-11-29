#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <memory>
#include <set>

#include "Message.hpp"
#include "Observer.hpp"

class Subject {
	public:
		void registerObserver(std::shared_ptr<Observer> observer);
		void unRegisterObserver(std::shared_ptr<Observer> observer);

		void notifyObservers(Message& msg);

	private:
		std::set< std::shared_ptr<Observer> > observers;
};

#endif

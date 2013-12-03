#include <iostream>

#include "Subject.hpp"

void Subject::registerObserver(std::shared_ptr<Observer> observer)
{
	observers.insert(observer);
}

void Subject::unRegisterObserver(std::shared_ptr<Observer> observer)
{
	observers.erase(observer);
}
  
void Subject::notifyObservers(Message& msg)
{
	for(auto& observer : observers) {
		observer->notify(msg);
	}
}


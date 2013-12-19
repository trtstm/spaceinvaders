#include <iostream>

#include "Subject.hpp"

Subject::~Subject()
{
}

void Subject::registerObserver(Observer& observer)
{
	observers.insert(&observer);
}

void Subject::unRegisterObserver(Observer& observer)
{
	observers.erase(&observer);
}

void Subject::unRegisterAll()
{
	observers.clear();
}
  
void Subject::notifyObservers(Message& msg)
{
	for(auto& observer : observers) {
		observer->notify(msg);
	}
}


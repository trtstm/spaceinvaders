#include <iostream>

#include "Subject.hpp"

Subject::~Subject()
{
	std::cout << "Deleted subject" << std::endl;
}

void Subject::registerObserver(std::shared_ptr<Observer> observer)
{
	observers.insert(observer);
}

void Subject::unRegisterObserver(std::shared_ptr<Observer> observer)
{
	observers.erase(observer);
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


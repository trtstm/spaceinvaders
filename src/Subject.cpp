#include <iostream>

#include "Subject.hpp"

Subject::~Subject()
{
}

void Subject::unRegisterAll()
{
	move.clear();
	collision.clear();
	died.clear();
}

void Subject::registerMove(Observer& observer)
{
	move.insert(&observer);
}

void Subject::unRegisterMove(Observer& observer)
{
	move.erase(&observer);
}
  
void Subject::registerCollision(Observer& observer)
{
	collision.insert(&observer);
}

void Subject::unRegisterCollision(Observer& observer)
{
	collision.erase(&observer);
}

void Subject::registerDied(Observer& observer)
{
	died.insert(&observer);
}

void Subject::unRegisterDied(Observer& observer)
{
	died.erase(&observer);
}

void Subject::notifyMove(Message& msg)
{
	for(auto& observer : move) {
		observer->notify(msg);
	}
}

void Subject::notifyCollision(Message& msg)
{
	for(auto& observer : collision) {
		observer->notify(msg);
	}
}

void Subject::notifyDied(Message& msg)
{
	for(auto& observer : died) {
		observer->notify(msg);
	}
}

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
	for(auto observer = move.begin(); observer != move.end();) {
		if(!(*observer)->notify(msg)) {
			observer = move.erase(observer);

			unRegisterCollision(*(*observer));
			unRegisterDied(*(*observer));
		} else {
			observer++;
		}
	}
}

void Subject::notifyCollision(Message& msg)
{
	for(auto observer = collision.begin(); observer != collision.end();) {
		if(!(*observer)->notify(msg)) {
			observer = collision.erase(observer);

			unRegisterMove(*(*observer));
			unRegisterDied(*(*observer));
		} else {
			observer++;
		}
	}
}

void Subject::notifyDied(Message& msg)
{
	for(auto observer = died.begin(); observer != died.end();) {
		if(!(*observer)->notify(msg)) {
			observer = died.erase(observer);

			unRegisterMove(*(*observer));
			unRegisterCollision(*(*observer));
		} else {
			observer++;
		}
	}
}

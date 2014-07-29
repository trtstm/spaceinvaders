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
	score.clear();
	menuSelection.clear();
	menuChange.clear();
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

void Subject::registerScore(Observer& observer)
{
	score.insert(&observer);
}

void Subject::unRegisterScore(Observer& observer)
{
	score.erase(&observer);
}

void Subject::registerMenuSelection(Observer& observer)
{
	menuSelection.insert(&observer);
}

void Subject::unRegisterMenuSelection(Observer& observer)
{
	menuSelection.erase(&observer);
}

void Subject::registerMenuChange(Observer& observer)
{
	menuChange.insert(&observer);
}

void Subject::unRegisterMenuChange(Observer& observer)
{
	menuChange.erase(&observer);
}

void Subject::notifyMove(Message::Message& msg)
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

void Subject::notifyCollision(Message::Message& msg)
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

void Subject::notifyDied(Message::Message& msg)
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

void Subject::notifyScore(Message::Message& msg)
{
	for(auto observer = score.begin(); observer != score.end();) {
		if(!(*observer)->notify(msg)) {
			observer = score.erase(observer);

			unRegisterScore(*(*observer));
		} else {
			observer++;
		}
	}
}

void Subject::notifyMenuSelection(Message::Message& msg)
{
	for(auto observer = menuSelection.begin(); observer != menuSelection.end();) {
		if(!(*observer)->notify(msg)) {
			observer = menuSelection.erase(observer);

			unRegisterMenuSelection(*(*observer));
		} else {
			observer++;
		}
	}
}

void Subject::notifyMenuChange(Message::Message& msg)
{
	for(auto observer = menuChange.begin(); observer != menuChange.end();) {
		if(!(*observer)->notify(msg)) {
			observer = menuChange.erase(observer);

			unRegisterMenuChange(*(*observer));
		} else {
			observer++;
		}
	}
}

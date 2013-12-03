#ifndef SPACESHIP_TEXT_VIEW_HPP
#define SPACESHIP_TEXT_VIEW_HPP

#include <memory>

#include "Observer.hpp"
#include "messages/Message.hpp"

class SpaceshipTextView : public Observer {
	public:
		bool notify(Message& msg);
};

#endif

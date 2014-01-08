#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "messages/Message.hpp"

class Observer {
	public:
		virtual ~Observer();

		virtual bool notify(Message::Message& msg) = 0;
};

#endif

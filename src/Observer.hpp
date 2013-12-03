#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "messages/Message.hpp"

class Observer {
	public:
		virtual bool notify(Message& msg) = 0;
};

#endif

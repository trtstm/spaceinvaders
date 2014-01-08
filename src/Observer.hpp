#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "messages/Message.hpp"

class Observer {
	public:
		virtual ~Observer();

		/**
		* Notify the observer.
		*
		* @param msg The message.
		* @return False if the subject should remove us from the observer list, else true.
		*/
		virtual bool notify(Message::Message& msg) = 0;
};

#endif

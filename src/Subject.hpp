#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <memory>
#include <set>

#include "messages/Message.hpp"
#include "Observer.hpp"

class Subject {
	public:
		virtual ~Subject();

		/**
		* Register for move messages.
		*
		* @param observer The observer.
		*/
		void registerMove(Observer& observer);

		/**
		* Unregister observer for move messages.
		*
		* @param observer The observer.
		*/
		void unRegisterMove(Observer& observer);

		/**
		* Register for collision messages.
		*
		* @param observer The observer.
		*/
		void registerCollision(Observer& observer);

		/**
		* Unregister observer for collision messages.
		*
		* @param observer The observer.
		*/
		void unRegisterCollision(Observer& observer);

		/**
		* Register for died messages.
		*
		* @param observer The observer.
		*/
		void registerDied(Observer& observer);

		/**
		* Unregister observer for died messages.
		*
		* @param observer The observer.
		*/
		void unRegisterDied(Observer& observer);

		/**
		* Unregister all observers.
		*/
		void unRegisterAll();

		/**
		* Notify to observers interested in move messages.
		*
		* @param msg The message.
		*/
		void notifyMove(Message::Message& msg);

		/**
		* Notify to observers interested in collision messages.
		*
		* @param msg The message.
		*/
		void notifyCollision(Message::Message& msg);

		/**
		* Notify to observers interested in died messages.
		*
		* @param msg The message.
		*/
		void notifyDied(Message::Message& msg);

	private:
		std::set<Observer*> move;
		std::set<Observer*> collision;
		std::set<Observer*> died;
};

#endif

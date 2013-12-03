#ifndef ENTITY_H
#define ENTITY_H

#include <map>
#include <string>
#include <memory>
#include <typeinfo>

class Component;

class Entity {
	public:
		virtual ~Entity() ;

		/**
		* Add a component.
		*
		* @param component The component to add. The pointer will be owned by this class from now on.
		*/
		template <class T>
		void setComponent(std::shared_ptr<T> component);	

		/**
		* Get a component.
		*
		* @param name The name corresponding to the component.
		*
		* @pre There is a component with the name.
		*/
		template <class T>
		T* getComponent();
		
		

	private:
		std::map< std::string, std::shared_ptr<Component> > components;
};

template <class T>
void Entity::setComponent(std::shared_ptr<T> component)
{
	components.erase(typeid(T).name());

	components[typeid(T).name()] = component;
}

template <class T>
T* Entity::getComponent()
{
	if(components.count(typeid(T).name()) != 1) {
		return 0;
	}

	return static_cast<T*>(components[typeid(T).name()].get());
}

#endif

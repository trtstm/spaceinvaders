#ifndef ENTITY_H
#define ENTITY_H

#include <map>
#include <string>
#include <memory>

class Component;

class Entity {
	public:
		virtual ~Entity() ;

		/**
		* Add a component.
		*
		* @param name The name corresponding to the component.
		* @param component The component to add. The pointer will be owned by this class from now on.
		*/
		void setComponent(const std::string& name, Component* component);	

		/**
		* Get a component.
		*
		* @param name The name corresponding to the component.
		*
		* @pre There is a component with the name.
		*/
		template <class T>
		T* getComponent(const std::string& name);
		
		

	private:
		std::map< std::string, std::unique_ptr<Component> > components;
};

template <class T>
T* Entity::getComponent(const std::string& name)
{
	if(components.count(name) != 1) {
		throw "No component with that name";
	}

	return static_cast<T*>(components[name].get());
}

#endif

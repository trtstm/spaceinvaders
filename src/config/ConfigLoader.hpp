#ifndef CONFIG_LOADER_H
#define CONFIG_LOADER_H

#include <string>
#include <iostream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/exceptions.hpp>
#include <boost/property_tree/json_parser.hpp>

class ConfigLoader {
	public:
		ConfigLoader();

		/*
		* Load a config file.
		*
		* @param file The file to load.
		* @return True if loaded, false otherwise.
		*/
		virtual bool load(std::string file);

		/*
		* Set a value for the key if it does not exist or is of wrong type.
		*
		* @param key The key.
		* @param value The value to set.
		*/
		template<class T>
		void setDefault(std::string key , T value);

		/*
		* Get the value at a key.
		*
		* @param key The key.
		* @return The value at the key.
		*/
		template<class T>
		T get(std::string key) const;

		/*
		* Set a value for the key.
		*
		* @param key The key.
		* @param value The value to set.
		*/
		template<class T>
		void put(std::string key, T value);

	protected:
		boost::property_tree::ptree pt;
};

template<class T>
void ConfigLoader::setDefault(std::string key, T value)
{
	auto setDefault = [&key, &value, this]() mutable {
		std::cerr << "config: setting default for " << key << ": " << value << std::endl;
		this->pt.put(key, value);
	};

	try {
		this->pt.get_child(key).get_value<T>();
	} catch(boost::property_tree::ptree_bad_path& err) {
		setDefault();
	} catch(boost::property_tree::ptree_bad_data& err) {
		std::cerr << "config: value of " << key << " has invalid type, should be: ";
		std::string type = "";
		if(typeid(int) == typeid(T)) {
			type = "int";
		} else if(typeid(std::string) == typeid(T)) {
			type = "string";
		} else {
			type = "unknown";
		}
		std::cerr << type << std::endl;
		setDefault();
	}
}

template<class T>
T ConfigLoader::get(std::string key) const
{
	return this->pt.get<T>(key);
}

template<class T>
void ConfigLoader::put(std::string key, T value)
{
	this->pt.put<T>(key, value);
}

#endif

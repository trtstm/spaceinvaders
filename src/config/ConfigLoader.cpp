#include "ConfigLoader.hpp"

ConfigLoader::ConfigLoader()
{
}

bool ConfigLoader::load(std::string file)
{
	using namespace boost::property_tree;

	try {
		read_json(file, this->pt);
	} catch(json_parser::json_parser_error e) {
		return false;
	}

	return true;
}

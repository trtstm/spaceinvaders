#include "GlobalLoader.hpp"

#include <vector>
#include <string>

bool GlobalLoader::load(std::string file)
{
	ConfigLoader::load(file);

	this->setDefault("resolution.x", 800);
	this->setDefault("resolution.y", 600);

	this->setDefault("fps", 60);

	std::vector<std::string> entities = {
		"invader", "spaceship", "bunkerleft", "bunkerright", "bunkermiddle", "lasercannon", "explosion"
	};

	for(auto& entity : entities) {
		try {
			auto graphics = this->pt.get_child(entity).get_child("graphics");

			if(entity == "invader") {
				graphics.get<std::string>("1");
				graphics.get<std::string>("2");
			} else if(entity == "spaceship") {
				graphics.get<std::string>("1");
			} else if(entity == "bunkerleft" || entity == "bunkerright" || entity == "bunkermiddle") {
				graphics.get<std::string>("1");
				graphics.get<std::string>("2");
				graphics.get<std::string>("3");
			} else if(entity == "lasercannon") {
				graphics.get<std::string>("1");
			} else if(entity == "explosion") {
				graphics.get<std::string>("1");
			}

			if(entity == "explosion") {
				continue;
			}

			this->pt.get_child(entity).get<int>("dimensions.x");
			this->pt.get_child(entity).get<int>("dimensions.y");

			if(entity == "invader" || entity == "lasercannon" || entity == "spaceship") {
				this->pt.get_child(entity).get<double>("speed");
			}

			if(entity == "invader" || entity == "spaceship") {
				this->pt.get_child(entity).get<int>("score");
			}

			if(entity == "invader") {
				this->pt.get_child(entity).get<double>("shoottime");
				this->pt.get_child(entity).get<double>("shootchance");
				this->pt.get_child(entity).get<int>("maxshots");
			}

			if(entity == "spaceship") {
				this->pt.get_child(entity).get<int>("spawntime");
			}

		} catch(boost::property_tree::ptree_bad_path& err) {
			std::cerr << "Could not read config for entity " << entity << ": " << err.what() << std::endl;
			return false;
		} catch(boost::property_tree::ptree_bad_data& err) {
			std::cerr << "Could not read config for entity " << entity << ": " << err.what() << std::endl;
			return false;
		}
	}

	std::vector<std::string> fonts = {
		"default",
		"mono"
	};

	for(auto& font : fonts) {
		setDefault<std::string>("fonts." + font, "");
	}

	try {
		for(const auto& kv : this->pt.get_child("levels")) {
			auto level = kv.second.get<std::string>("");
			LevelLoader loader;
			if(!loader.load("../resources/levels/" + level + ".json")) {
				std::cerr << "could not load level: ../resources/levels/" << level << ".json" << std::endl;
				return false;
			}
			levels.push_back(loader);
		}
	} catch(boost::property_tree::ptree_bad_path& err) {
		std::cerr << "could not find levels in config" << std::endl;
		return false;
	} catch(boost::property_tree::ptree_bad_data& err) {
		std::cerr << "could not load level, levels should only contain strings" << std::endl;
		return false;
	}

	return true;
}

int GlobalLoader::getResolutionX() const
{
	return this->pt.get<int>("resolution.x");
}

int GlobalLoader::getResolutionY() const
{
	return this->pt.get<int>("resolution.y");
}

int GlobalLoader::getFps() const
{
	return this->pt.get<int>("fps");
}

std::map<std::string, std::string> GlobalLoader::getGraphics() const
{
	std::vector<std::string> entities = {
		"invader", "spaceship", "bunkerleft", "bunkerright", "bunkermiddle", "lasercannon", "explosion"
	};

	std::map<std::string, std::string> result;

	for(auto& entity : entities) {
		for(const auto& kv : this->pt.get_child(entity).get_child("graphics")) {
			result[entity + kv.first] = kv.second.get<std::string>("");
		}
	}



	return result;
}

std::map<std::string, std::string> GlobalLoader::getFonts() const
{
	std::map<std::string, std::string> result;

	for(const auto& kv : this->pt.get_child("fonts")) {
		result[kv.first] = kv.second.get<std::string>("");
	}

	return result;
}

std::vector<LevelLoader> GlobalLoader::getLevels() const
{
	return levels;
}

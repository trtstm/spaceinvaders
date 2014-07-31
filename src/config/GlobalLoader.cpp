#include "GlobalLoader.hpp"

#include <vector>
#include <string>

bool GlobalLoader::load(std::string file)
{
	ConfigLoader::load(file);

	this->setDefault("resolution.x", 800);
	this->setDefault("resolution.y", 600);

	this->setDefault("fps", 60);

	this->setDefault("players", 1);
	if(this->getPlayers() != 1 && this->getPlayers() != 2) {
		this->pt.put("players", 1);
	}

	std::vector<std::string> graphics = {
		"bunkerleft1", "bunkerleft2", "bunkerleft3",
		"bunkermiddle1", "bunkermiddle2", "bunkermiddle3",
		"bunkerright1", "bunkerright2", "bunkerright3",

		"explosion",

		"invader1", "invader2",

		"lasercannon",

		"spaceship"
	};

	for(auto& graphic : graphics) {
		setDefault<std::string>("graphics." + graphic, "");
	}

	std::vector<std::string> fonts = {
		"default"
	};

	for(auto& font : fonts) {
		setDefault<std::string>("fonts." + font, "");
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

int GlobalLoader::getPlayers() const
{
	return this->pt.get<int>("players");
}

std::map<std::string, std::string> GlobalLoader::getGraphics() const
{
	std::map<std::string, std::string> result;

	for(const auto& kv : this->pt.get_child("graphics")) {
		result[kv.first] = kv.second.get<std::string>("");
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

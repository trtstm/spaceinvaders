#include "GlobalLoader.hpp"

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

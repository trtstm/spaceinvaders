#include "GlobalLoader.hpp"

bool GlobalLoader::load(std::string file)
{
	ConfigLoader::load(file);

	this->setDefault("resolution.x", 800);
	this->setDefault("resolution.y", 600);

	this->setDefault("fps", 60);

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

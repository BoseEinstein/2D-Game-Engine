#include "../include/ResourceManager.h"
#include <pybind11/pybind11.h>
namespace py = pybind11;
ResourceManager *ResourceManager::instance = 0;

 ResourceManager *ResourceManager::getInstance() {


	if (!instance) {
		instance = new ResourceManager();
	}

	return instance;


}

SDL_Surface* ResourceManager::loadResource(std::string resourceName) {

	//Loads a resource onto the resourceMap or increments the element if already present
	auto itr = resourceMap.find(resourceName);
	if (itr == resourceMap.end()) {
		SDL_Surface *newSurface = IMG_Load(resourceName.c_str());
		resourceMap.insert(make_pair(resourceName, newSurface));
		resourceCount.insert(make_pair(resourceName, 1));
		return newSurface;

	}
	else {
		py::print("Found resource");
		auto count_itr = resourceCount.find(resourceName);
		count_itr->second++;
		py::print("Return resource");
		return itr->second;
	}

}

void ResourceManager::unloadResource(std::string resourceName) {

	auto count_itr = resourceCount.find(resourceName);
	count_itr->second--;
	if (count_itr->second <= 0) {
		auto itr = resourceMap.find(resourceName);
		SDL_Surface* oldResource = itr->second;
		SDL_FreeSurface(oldResource);
		resourceMap.erase(resourceName);
	}


}

Mix_Chunk *ResourceManager::loadSound(std::string resourceName) {
	Mix_Chunk *sound;
	//Load sound asset
	sound = Mix_LoadWAV(resourceName.c_str());
	//Check if sound asset was loaded correctly
	if (sound == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		
	}

	return sound;

}

Mix_Music *ResourceManager::loadMusic(std::string resourceName) {
	Mix_Music *music;
	//Load music asset
	music = Mix_LoadMUS(resourceName.c_str());
	//Check if music asset was loaded correctly
	if (music == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	}

	return music;
}

ResourceManager::ResourceManager() {

}
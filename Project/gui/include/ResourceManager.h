#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include "SDLProgram.h"
#include <map>
#include <string>

class ResourceManager {

public:
	static ResourceManager *getInstance();

	/**
	Loads the resource specified by the resourceName. If the resource
	has already been loaded into memory it returns a pointer to the
	existing resource, loads new resource otherwise.
	*/
	SDL_Surface *loadResource(std::string resourceName);
	/**
	If the resourceName provided is not in use by any other objects
	then the resource will be unloaded from memory.
	*/
	void unloadResource(std::string resourceName);

	/*
	Load a sound file into a chunk
	*/
	Mix_Chunk *loadSound(std::string resourceName);
	/*
	Load a music file into a Mix_music object for playing
	*/
	Mix_Music *loadMusic(std::string resourceName);

private:
	static ResourceManager* instance;
	std::map<std::string, SDL_Surface*> resourceMap;
	std::map<std::string, int> resourceCount;
	ResourceManager();

};




#endif

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "GameObject.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

class FileManager {
public:
	/*
	Construct a basic file manager to save and read game files
	*/
	FileManager();
	~FileManager();
	/*
	Save the given game object to a file
	*/
	std::string saveGameObject(GameObject *o, std::string fileName);
	/*
	Load a single game object from a file
	*/
	GameObject *loadGameObject(std::string fileName, int globalID);
	/*
	Save a whole scenes objects to files. Scene is saved at file name provided
	*/
	std::string saveGame(std::map<int, GameObject*> objects, std::string fileName);
	/*
	Load a full scene from file provided into the engine
	*/
	std::map<int, GameObject*> loadGame(std::string fileName);
};
#endif
#pragma once


#include <string>
#include "AudioManager.h"
#include "Collider.h"
#include "GameObject.h"
#include "ImageComponent.h"
#include "ImgFlipEnum.h"
#include "LTexture.h"
#include "ResourceManager.h"
#include "SDLProgram.h"
#include "TextComponent.h"
#include "TinyMath.h"
#include "Transform.h"
#include <stdio.h>
#include "FileManager.h"
#include "Input.h"


class GameEngine {
	
public:
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Start up an empty game engine
	*/
	GameEngine();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Start game engine with given window size
	*/
	GameEngine(int width, int height);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Change the dispaly window size
	*/
	void setGameWindowSize(int width,int height);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Add a new game object to the scene with the provided name
	*/
	GameObject *addObject(std::string name);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Delete and object from the scene as identified by the id
	*/
	void deleteObject(int id);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Retrieve a game object from the engine by its name
	*/
	GameObject *findObjectByName(std::string name);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Retrieve a game object from the engine by its unique ID*/
	GameObject *findObjectByID(int id);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Retrieve the input system maintained by the engine
	*/
	Input *getInputSystem();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Set the frame cap for the game to run at
	*/
	void setFrameCap(int FPS);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Render all objects that called a render function to the screen
	*/
	void renderScreen();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Clear the screen of old objects
	*/
	void clearScreen();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Call before all other function calls and then call endFrame after all calls to lock your fps to what was set.
	*/
	void startFrame();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Call after all other function calls and call startFrame before all calls to lock your fps to what was set.
	*/
	void endFrame();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Read a saved scene of objects into the engine
	*/
	void readGameFile(std::string fileName);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Save the state of the objects in the engine to file
	*/
	void saveGameFile(std::string fileName);


private:
	Input* _inputSystem;
	FileManager _fm;
	int nextObjectID = 0;
	std::map<int, GameObject*> _objectList;
	std::map<std::string, int> _nameToIDMap;
	int DESIRED_FRAME_RATE = 60;
	int SCREEN_TICKS_PER_FRAME = 1000 / DESIRED_FRAME_RATE;
	unsigned int currentTime;
	


};




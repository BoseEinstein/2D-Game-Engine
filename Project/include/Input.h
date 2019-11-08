#pragma once
#include "SDLProgram.h"
#include <string>
#include <map>
class Input {
public:
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Nothing Special about this.
	*/
	Input();
	~Input();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Register a keyboard input as defined by its char to an alias string.
	Can register A-Z, 0-9 and SPACE
	*/
	void registerInput(std::string alias, char key);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Returns the alias string of an input that was detected on the frame
	*/
	std::string checkForInput();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Returns alias plus "-" on the front for input released this frame
	*/
	std::string checkForInputRelease();


private:
	SDL_Event _e;
	std::map<SDL_Keycode , std::string> inputBindings;
};
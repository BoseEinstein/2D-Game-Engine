
#ifndef SDLPROGRAM_H
#define SDLPROGRAM_H
//Using SDL, SDL_image, standard IO, and strings
#if defined(LINUX) || defined(MINGW)
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#else
	// Windows and Mac use a different path
	// If you have compilation errors, change this as needed.
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#endif
#include <stdio.h>


class SDLProgram{
public:


	static SDLProgram *getInstance();


	/**
	Starts up SDL and creates window
	*/
	bool init();

	//Frees media and shuts down SDL
	void close();

	/**
	Returns and active renderer for other classes to draw with.
	*/
	SDL_Renderer* getRenderer();

	/**
	Returns true if SDL was launched without issue.
	*/
	bool started();

	/*
	Change the size of the window that is being rendered to.
	*/
	bool setRenderWindow(int screenWidth, int screenHeight);




private:

	bool success;
	int screenWidth =720, screenHeight=480;

	static SDLProgram* instance;

	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	//The window renderer
	SDL_Renderer* gRenderer = NULL;

	SDLProgram();
	~SDLProgram();
};
#endif

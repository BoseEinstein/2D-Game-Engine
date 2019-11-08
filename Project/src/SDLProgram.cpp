#include "../include/SDLProgram.h"

SDLProgram *SDLProgram::instance = 0;

SDLProgram::SDLProgram()
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
		exit(0);
	}
}


SDLProgram::~SDLProgram()
{
	close();
}

SDLProgram *SDLProgram::getInstance() {


	if (!instance) {
		instance = new SDLProgram();
	}

	return instance;

}

bool SDLProgram::started() {
	return success;
}

SDL_Renderer* SDLProgram::getRenderer() {
	return gRenderer;
}

bool SDLProgram::setRenderWindow(int screenWidth, int screenHeight) {
	bool winSuccess = true;

	//The window we'll be rendering to
	SDL_Window* oldWindow = gWindow;

	//The window renderer
	SDL_Renderer* oldRenderer = gRenderer;

	//Create window
	gWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	if (gWindow == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		winSuccess = false;
	}
	else {
		//Create vsynced renderer for window
		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (gRenderer == NULL)
		{
			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			winSuccess = false;
		}
	}

	if (winSuccess) {
		if (oldRenderer != NULL) {
			SDL_DestroyRenderer(oldRenderer);
		}

		if (oldWindow != NULL) {
			SDL_DestroyWindow(oldWindow);
		}
	}
	
	return winSuccess;
}

bool SDLProgram::init()
{
	//Initialization flag
	success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("Platformer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if (!setRenderWindow(screenWidth,screenHeight))
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			
			
			//Initialize renderer color
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}
			//Initialize SDL_ttf
			if (TTF_Init() == -1)
			{
				printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
				success = false;
			}

			//Initialize SDL_mixer
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
			{
				printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
				success = false;
			}
			
		}
	}

	return success;
}

void SDLProgram::close()
{

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;



	//Quit SDL subsystems
	IMG_Quit();
	TTF_Quit();
	Mix_Quit();
	SDL_Quit();
}

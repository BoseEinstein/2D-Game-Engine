#ifndef LTEXTURE_H
#define LTEXTURE_H
#include"SDLProgram.h"

#include <stdio.h>
#include <string>
#include"ResourceManager.h"

//Texture wrapper class
//Class largely used from http://lazyfoo.net/tutorials/SDL/index.php
class LTexture
{
public:
	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();

	/**
	Loads image at specified path using the ResourceManager and assigns it to mTexture.
	*/
	bool loadFromFile(std::string path);


	/**
	Creates a texture out of the string provided and is assigned to mTexture.
	*/
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor, TTF_Font *gFont, SDL_Renderer* gRenderer);

	//Deallocates texture
	void free();

	//Renders texture at given point
	void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	/**
	Returns texture Width.
	*/
	int getWidth();

	/**
	Returns texture Height.
	*/
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};
#endif

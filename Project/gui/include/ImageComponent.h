#pragma once

#include "LTexture.h"
#include "ImgFlipEnum.h"
#include <string>

class ImageComponent {

public:
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Construct Empty Image Component
	*/
	ImageComponent();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Construct image component with image at given file location
	*/
	ImageComponent( std::string imgFile);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Construct image component with image at given file location and split into an animation of sprites
	with the given number of frames sprite dimensions and frame rate
	*/
	ImageComponent( std::string imgFile, int animFrames, int spriteWidth, int spriteHeight, int animFrameRate);
	~ImageComponent();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Change the image of the component to the image at the file location
	*/
	bool setImage(std::string imgFile);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Render image at given coordinate regardless of parent objects transform
	*/
	void render(int x, int y, double angle = 0.0, ImgFlipEnum flip = ImgFlipEnum::NONE);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Set animation parameters to split image into an animation of sprites
	with the given number of frames sprite dimensions and frame rate*/
	bool setAnimationFrames(int animFrames, int spriteWidth, int spriteHeight, int animFrameRate, bool startAnim);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Set if the current animation should be running and what frame to start up on
	*/
	void setShouldAnimate(bool shouldAnim, int currAnimFrame);
	/*
	
	Retrieve the file name of the image loaded on this component
	*/
	std::string getImageFile();
	/*
	
	Get the sprite height of animations, returns 0 if no animation
	*/
	int getSpriteHeight();
	/*
	
	Get the sprite width of animations, returns 0 if no animation
	*/
	int getSpriteWidth();
	/*
	
	Get the framerate of the animation, returns 0 if no animation
	*/
	int getanimFrameRate();
	/*
	Return if this component should be animating
	*/
	int getShouldAnim();
	/*

	Get the number of frames in the animation
	*/
	int getAnimFrames();

private:
	std::string _imgFile;
	LTexture imgTexture;
	unsigned int _lastAnimTime;
	SDL_Rect anim[100];
	int _animFrames = 1;
	int _spriteWidth = 0;
	int _spriteHeight = 0;
	int _animFPS = 1;
	int _currAnimFrame = 0;
	bool _shouldAnim = false;
	int _ticksPerAnimFram = 1 / _animFPS;
};
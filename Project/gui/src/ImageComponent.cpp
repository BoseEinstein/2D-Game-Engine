#include "../include/ImageComponent.h"
#include <pybind11/pybind11.h>
namespace py = pybind11;
ImageComponent::ImageComponent()  {
	//setImage("background.png");
}

ImageComponent::ImageComponent( std::string imgFile)  {
	setImage(imgFile);
	
}

ImageComponent::ImageComponent( std::string imgFile, int animFrames, int spriteWidth, int spriteHeight, int animFrameRate) {
	if (setImage(imgFile)) {

	}
	else if(!setAnimationFrames(animFrames, spriteWidth, spriteHeight, animFrameRate, false)) {
		printf("Error Setting up animation");
	}
}

ImageComponent::~ImageComponent() {
	ResourceManager::getInstance()->unloadResource(_imgFile);
}

bool ImageComponent::setAnimationFrames(int animFrames, int spriteWidth, int spriteHeight, int animFrameRate, bool startAnim) {
	_animFrames = animFrames;
	_animFPS = animFrameRate;
	_ticksPerAnimFram = 1000 / _animFPS;
	_shouldAnim = startAnim;
	_spriteWidth = spriteWidth;
	_spriteHeight = spriteHeight;
	int sheetWidth = imgTexture.getWidth();
	int sheetHeight = imgTexture.getHeight();
	int framesAcross = sheetWidth / _spriteWidth;
	int framesVert = sheetHeight / _spriteHeight;

	if (_animFrames > framesAcross * framesVert || _animFrames > 100) {
		printf("Invalid Dimensions/Anim Frames Provided");
		py::print("anim frames invalid");
		py::print(_animFrames);
		py::print(framesAcross * framesVert);
		py::print(sheetWidth);
		py::print(sheetHeight);
		py::print(_spriteWidth);
		py::print(_spriteHeight);
		return false;
	}

	for (int i = 0; i < _animFrames; i++) {
		anim[i].x = (i % framesAcross) * _spriteWidth;
		anim[i].y = (i / framesAcross) * _spriteHeight;
		anim[i].w = _spriteWidth;
		anim[i].h = _spriteHeight;
	}

	return true;
}

void ImageComponent::setShouldAnimate(bool shouldAnim, int currAnimFrame) {
	_shouldAnim = shouldAnim;
	_currAnimFrame = currAnimFrame;
}

bool ImageComponent::setImage(std::string imgFile) {

	
	if (!imgTexture.loadFromFile(imgFile)) {
		printf("Failed to Load Image");
		return false;
	}
	_spriteWidth = imgTexture.getWidth();
	_spriteHeight = imgTexture.getHeight();
	_imgFile = std::string(imgFile);
	py::print("Assigned image: " + _imgFile);

	return true;
}


void ImageComponent::render(int x, int y, double angle , ImgFlipEnum flip) {
	SDL_RendererFlip rFlip;
	
	switch (flip) {
	case ImgFlipEnum::NONE:
		rFlip = SDL_FLIP_NONE;
		break;
	case ImgFlipEnum::HORIZONTAL:
		rFlip = SDL_FLIP_HORIZONTAL;
		break;
	case ImgFlipEnum::VERTICAL:
		rFlip = SDL_FLIP_VERTICAL;
		break;
	case ImgFlipEnum::BOTH:
		rFlip = (SDL_RendererFlip) (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
		break;
	default:
		rFlip = SDL_FLIP_NONE;
		break;
	}
	
	
	if (_animFrames < 2) {
		imgTexture.render( x, y, NULL, angle,(SDL_Point*)0,rFlip);
	}
	else {
		if (_shouldAnim) {
			unsigned int _currentTime = SDL_GetTicks();
			if (_currentTime - _lastAnimTime > _ticksPerAnimFram){
				_currAnimFrame++;
				_lastAnimTime = SDL_GetTicks();

			}
			if (_currAnimFrame >= _animFrames) {
				_currAnimFrame = 0;
			}

		}

		imgTexture.render( x, y, &anim[_currAnimFrame], angle, (SDL_Point*)0, rFlip);


	}
}


std::string ImageComponent::getImageFile() {
	return std::string(_imgFile);
}

int ImageComponent::getanimFrameRate() {
	return _animFPS;
}

int ImageComponent::getShouldAnim() {
	return _shouldAnim;
}

int ImageComponent::getSpriteHeight() {
	return _spriteHeight;
}

int ImageComponent::getSpriteWidth() {
	return _spriteWidth;
}

int ImageComponent::getAnimFrames(){
	return _animFrames;
}
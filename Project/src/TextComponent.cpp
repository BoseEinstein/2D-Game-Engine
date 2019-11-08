#include "../include/TextComponent.h"

TextComponent::TextComponent() {
	_font = TTF_OpenFont("Acme-Regular.ttf", 28);
	setText("O");
}

TextComponent::TextComponent( std::string text)  {
	setText(text);
	_font = TTF_OpenFont("Acme-Regular.ttf", 28);
}

TextComponent::~TextComponent() {
	_textTexture.free();
}


bool TextComponent::setText(std::string text) {
	//Loading success flag
	bool success = true;
	
	//Load dot texture
	SDL_Color textColor = { 0, 0, 0 };
	if (!_textTexture.loadFromRenderedText(text, textColor, _font, SDLProgram::getInstance()->getRenderer()))
	{
		printf("Failed to set text texture!\n");
		success = false;
	}
	_text = std::string(text);
	return success;
}

void TextComponent::setActive(bool val){
	_active = val;
}

bool TextComponent::isActive(){
	return _active;
}

void TextComponent::render(int x, int y, double angle, ImgFlipEnum flip ) {

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
		rFlip = (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
		break;
	default:
		rFlip = SDL_FLIP_NONE;
		break;
	}

	_textTexture.render( x, y, NULL, angle, (SDL_Point*)0, rFlip);
}

std::string TextComponent::getText() {
	return _text;
}
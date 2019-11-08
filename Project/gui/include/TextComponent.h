#pragma once

#include "LTexture.h"
#include <string>
#include "ImgFlipEnum.h"


class TextComponent {

public:
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Construct and empty TextComponent
	*/
	TextComponent();

	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Construc Text Component with given text string*/
	TextComponent( std::string text);

	~TextComponent();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Change the text represented by the component
	*/
	bool setText(std::string text);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Render text at given coordinate regardless of parent objects transform
	*/
	void render(int x, int y,  double angle = 0.0, ImgFlipEnum flip = ImgFlipEnum::NONE);
	/*
	Get the text represented by the component*/
	std::string getText();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Set if this component is active or not
	*/
	void setActive(bool val);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Return true if this component is currently active
	*/
	bool isActive();
	
	
private:
	bool _active = false;
	TTF_Font *_font = NULL;
	LTexture _textTexture;
	std::string _text;
};
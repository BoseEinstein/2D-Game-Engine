#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Transform.h"
#include "Collider.h"
#include "AudioManager.h"
#include "ImageComponent.h"
#include "TextComponent.h"

class GameObject 
{
public:
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Create Game Object With Given ID
	*/
	GameObject(int globalID);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Create Game Object With Given ID and name
	*/
	GameObject(int globalID, std::string name);
	~GameObject();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Set the name of the object
	*/
	void setName(std::string name);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Retrieve the assigned name of the object
	*/
	std::string getName();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Get the Transform component of the object
	*/
	Transform *getTransform();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Get the Collider component of the object
	*/
	Collider *getCollider();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Get the image component of the object
	*/
	ImageComponent *getImageComponent();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Get the text component of teh object
	*/
	TextComponent *getTextComponent();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Get the audio componenet of the object
	*/
	AudioManager *getAudioComponent();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Return true if the current object is active
	*/
	bool isActive();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Set the current object active state based on parameter
	*/
	void setActive(bool active);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Retrieve the unique global ID of the object
	*/
	int getGlobalID();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Check if this object collided with another object
	*/
	bool checkCollision(GameObject &other);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Set the objects unique ID number*/
	void setGlobalID(int globalID);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Render this object at its current transform position and orientation*/
	void render( ImgFlipEnum flip = ImgFlipEnum::NONE);



private:
	void initComps(int globalID);
	ImageComponent *_img;
	AudioManager *_audio;
	Collider *_collider;
	TextComponent *_text;
	std::string _name = "GameObject";
	Transform *_transform;
	int _globalID;
	bool _active;

};
#endif
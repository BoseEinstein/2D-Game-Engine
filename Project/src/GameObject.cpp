#include "../include/GameObject.h"

#include <pybind11/pybind11.h>
namespace py = pybind11;
GameObject::GameObject(int globalID) {
	initComps(globalID);
}

GameObject::GameObject(int globalID, std::string name) {
	initComps(globalID);
	_name = name;

}

GameObject::~GameObject() {

}

void GameObject::initComps(int globalID) {
	_active = true;
	_globalID = globalID;
	_transform = new Transform();
	_img = new ImageComponent();
	_audio = new AudioManager();
	_text = new TextComponent();
	_collider = new Collider();
}

void GameObject::setGlobalID(int globalID) {
	_globalID = _globalID;
}


void GameObject::setName(std::string name){
	_name = name;
}


int GameObject::getGlobalID() {
	return _globalID;
}

Transform* GameObject::getTransform() {
	return _transform;
}

bool GameObject::checkCollision(GameObject &other) {

	Transform *to = other.getTransform();
	

	float xo = to->getX();
	float yo = to->getY();
	Collider *co =  other.getCollider();
	

	if(_active && other.isActive()){
		return (_transform->getX() < xo + co->getWidth() &&
			_transform->getX() + _collider->getWidth() > xo &&
			_transform->getY() < yo + co->getHeight() &&
			_transform->getY() + _collider->getHeight() > yo);
	}
	
	
}

void GameObject::render( ImgFlipEnum flip) {
	if (_active) {
		_img->render(_transform->getX(), _transform->getY(), _transform->getRotate(),flip);
		if(_text->isActive()){
			_text->render(_transform->getX(), _transform->getY(), _transform->getRotate(), flip);
		}
		
	}
}

std::string GameObject::getName() {
	return _name;
}



AudioManager* GameObject::getAudioComponent() {
	return _audio;
}

ImageComponent* GameObject::getImageComponent() {
	return _img;
}

TextComponent* GameObject::getTextComponent() {
	return _text;
}

Collider* GameObject::getCollider() {
	return _collider;
}

bool GameObject::isActive() {
	return _active;
}

void GameObject::setActive(bool active) {
	_active = active;
}

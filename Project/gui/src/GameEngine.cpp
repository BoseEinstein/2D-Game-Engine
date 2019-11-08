#include "../include/GameEngine.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace py = pybind11;
GameEngine::GameEngine(){
	py::print("Engine Started");
	_inputSystem = new Input();
}

GameEngine::GameEngine(int width, int height){
	_inputSystem = new Input();
	setGameWindowSize(width, height);
}

void GameEngine::setGameWindowSize(int width, int height) {
	SDLProgram::getInstance()->setRenderWindow(width, height);
}

GameObject* GameEngine::addObject(std::string name) {
	if (_nameToIDMap.find(name) == _nameToIDMap.end()) {

		_nameToIDMap.insert(std::pair<std::string, int>(name, nextObjectID));
		//py::print("inserted: " + name);
		GameObject *nextObject = new GameObject(nextObjectID, name);
		_objectList.insert(std::pair<int, GameObject*>(nextObjectID, nextObject));
		nextObjectID++;
		return nextObject;
	}
	else {
		return NULL;
	}
}

GameObject* GameEngine::findObjectByID(int id) {
	std::map<int, GameObject*>::iterator it = _objectList.find(id);

	if (it != _objectList.end()) {
		return it->second;
	}
	else {
		return NULL;
	}
}

GameObject* GameEngine::findObjectByName(std::string name) {
	std::map<std::string, int>::iterator it = _nameToIDMap.find(name);

	if (it != _nameToIDMap.end()) {
		return findObjectByID(it->second);
	}
	else {
		return NULL;
	}
}

Input* GameEngine::getInputSystem() {
	return _inputSystem;
}

void GameEngine::deleteObject(int id) {
	std::map<int, GameObject*>::iterator it = _objectList.find(id);

	if (it != _objectList.end()) {
		GameObject *delObj = it->second;
		std::string oldName = delObj->getName();
		_nameToIDMap.erase(oldName);
		_objectList.erase(id);
		delete delObj;
	}
}

void GameEngine::saveGameFile(std::string fileName) {
	py::print("In save game function");
	_fm.saveGame(_objectList, fileName);

	

}

void GameEngine::readGameFile(std::string fileName) {
	_objectList = _fm.loadGame(fileName);
	std::map<int, GameObject*>::iterator it;

	for (it = _objectList.begin(); it != _objectList.end(); ++it) {
		_nameToIDMap.insert(std::pair<std::string, int>(it->second->getName(), it->first));
		
	}
}

void GameEngine::clearScreen() {
	SDL_SetRenderDrawColor(SDLProgram::getInstance()->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(SDLProgram::getInstance()->getRenderer());
}

void GameEngine::renderScreen() {
	SDL_RenderPresent(SDLProgram::getInstance()->getRenderer());
}

void GameEngine::startFrame() {
	currentTime = SDL_GetTicks();
}

void GameEngine::setFrameCap(int FPS) {
	DESIRED_FRAME_RATE = FPS;
	SCREEN_TICKS_PER_FRAME = 1000 / DESIRED_FRAME_RATE;
}

void GameEngine::endFrame() {
	// If frame finished early delay
	if (SDL_GetTicks() - currentTime < SCREEN_TICKS_PER_FRAME) {
		SDL_Delay(SCREEN_TICKS_PER_FRAME - (SDL_GetTicks() - currentTime));
	}
}




PYBIND11_MODULE(ge, m) {

	py::class_<GameEngine>(m, "GameEngine")
		.def(py::init())
		.def(py::init<int, int>())
		.def("addObject", &GameEngine::addObject)
		.def("deleteObject", &GameEngine::deleteObject)
		.def("findObjectByID", &GameEngine::findObjectByID)
		.def("findObjectByName", &GameEngine::findObjectByName)
		.def("clearScreen", &GameEngine::clearScreen)
		.def("renderScreen", &GameEngine::renderScreen)
		.def("startFrame", &GameEngine::startFrame)
		.def("endFrame", &GameEngine::endFrame)
		.def("saveGameFile", &GameEngine::saveGameFile)
		.def("readGameFile", &GameEngine::readGameFile)
		.def("setFrameCap", &GameEngine::setFrameCap)
		.def("getInputSystem", &GameEngine::getInputSystem)
		.def("setGameWindowSize", &GameEngine::setGameWindowSize);

    py::class_<GameObject> gameObj(m,"GameObject");

    gameObj.def(py::init<int>(),py::arg("globalID"))
        .def(py::init<int,std::string>(), py::arg("globalID"), py::arg("name"))
        .def("getTransform",&GameObject::getTransform)
        .def("isActive", &GameObject::isActive)
        .def("setActive", &GameObject::setActive)
        .def("getGlobalID", &GameObject::getGlobalID)
        .def("getImageComponent", &GameObject::getImageComponent)
        .def("getTextComponent", &GameObject::getTextComponent)
        .def("getAudioComponent", &GameObject::getAudioComponent)
        .def("getCollider", &GameObject::getCollider)
        .def("setName", &GameObject::setName)
		.def("getName", &GameObject::getName)
		.def("render", &GameObject::render)
        .def("checkCollision", &GameObject::checkCollision);

	
    py::class_<Transform>(m,"Transform")
        .def(py::init())
        .def(py::init<float,float,float>())
        .def("getX", &Transform::getX)
        .def("getY", &Transform::getY)
        .def("getRotate", &Transform::getRotate)
        .def("setX", &Transform::setX)
        .def("setY", &Transform::setY)
        .def("setRotate", &Transform::setRotate)
        .def("isActive", &Transform::isActive)
        .def("setActive", &Transform::setActive);
	
    py::class_<AudioManager>(m, "AudioManager")
        .def(py::init())   // our constructor
        .def("playSound", &AudioManager::playSound) // Expose member methods
        .def("playMusic", &AudioManager::playMusic) 
        .def("loadMusic", &AudioManager::loadMusic) 
		.def("getMusicFile", &AudioManager::getMusicFile)
		.def("getSoundFile", &AudioManager::getSoundFile)
        .def("loadSound", &AudioManager::loadSound);
		
    py::class_<Collider>(m,"Collider")
        .def(py::init())
        .def(py::init<float,float,float,float>(), py::arg("x"),py::arg("y"),py::arg("width"),py::arg("height"))
        .def("setColliderSize", &Collider::setColliderSize)
        .def("getX", &Collider::getX)
        .def("getY", &Collider::getY)
        .def("getWidth", &Collider::getWidth)
        .def("getHeight", &Collider::getHeight);
		
    py::class_<TextComponent>(m,"TextComponent")
        .def(py::init())
        .def(py::init<std::string>(),py::arg("text") )
        .def("setText",&TextComponent::setText)
        .def("setActive", &TextComponent::setActive)
        .def("isActive", &TextComponent::isActive)
        .def("render", &TextComponent::render);

    py::class_<ImageComponent>(m,"ImageComponent")
        .def(py::init())
        .def(py::init<std::string>())
        .def(py::init<std::string,int,int,int,int>())

        .def("setImage", &ImageComponent::setImage)
        .def("render",&ImageComponent::render)
		.def("getImageFile", &ImageComponent::getImageFile)
        .def("setAnimationFrames",&ImageComponent::setAnimationFrames)
        .def("setShouldAnimate", &ImageComponent::setShouldAnimate);

    py::class_<Input>(m,"Input")
    	.def(py::init())
    	.def("registerInput", &Input::registerInput)
    	.def("checkForInputRelease", &Input::checkForInputRelease)
    	.def("checkForInput", &Input::checkForInput);
		
    py::enum_<ImgFlipEnum>(m, "ImgFlip")
        .value("NONE", ImgFlipEnum::NONE)
        .value("VERTICAL", ImgFlipEnum::VERTICAL)
        .value("HORIZONTAL", ImgFlipEnum::HORIZONTAL)
        .value("BOTH", ImgFlipEnum::BOTH)
        .export_values();

        

}



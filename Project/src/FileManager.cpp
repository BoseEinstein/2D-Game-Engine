#include "../include/FileManager.h"
#include <pybind11/pybind11.h>
namespace py = pybind11;
FileManager::FileManager() {

}

FileManager::~FileManager() {

}

std::string FileManager::saveGameObject(GameObject *o, std::string s) {
	std::ofstream myFile;
	myFile.open(s + ".txt");
	myFile << "NAME: " << o->getName() << "\n";
	myFile << "GLOBAL ID: " << o->getGlobalID() << "\n";
	if (o->isActive()) {
		myFile << "ACTIVE: TRUE\n";
	}
	else {
		myFile << "ACTIVE: FALSE\n";
	}
	py::print("saving Music");
	//myFile << "MUSIC: " << o->getAudioComponent()->getMusicFile() << "\n";
	py::print("saving Sound");
	//myFile << "SOUND: " << o->getAudioComponent()->getSoundFile() << "\n";
	py::print("saving Image: ");
	//myFile << "IMAGE: " << o->getImageComponent()->getImageFile() << "\n";
	py::print("saving anim");
	myFile << "ANIM_FRAMES: " << o->getImageComponent()->getAnimFrames() << "\n";
	myFile << "SPRITE_W: " << o->getImageComponent()->getSpriteWidth() << "\n";
	myFile << "SPRITE_H: " << o->getImageComponent()->getSpriteHeight() << "\n";
	myFile << "FRAME_RATE: " << o->getImageComponent()->getanimFrameRate() << "\n";
	
	if (o->getImageComponent()->getShouldAnim()) {
		myFile << "SHOULD_ANIM: TRUE" << "\n";
	} 
	else {
		myFile << "SHOULD_ANIM: FALSE" << "\n";
	}

	py::print("Saving text");
	//myFile << "TEXT: " << o->getTextComponent()->getText() << "\n";
	myFile << "COLLIDER_X: " << o->getCollider()->getX() << "\n";
	myFile << "COLLIDER_Y: " << o->getCollider()->getY() << "\n";
	myFile << "COLLIDER_W: " << o->getCollider()->getWidth() << "\n";
	myFile << "COLLIDER_H: " << o->getCollider()->getHeight() << "\n";
	myFile << "TRANSFORM_X: " << o->getTransform()->getX() << "\n";
	myFile << "TRANSFORM_Y: " << o->getTransform()->getY() << "\n";
	myFile << "TRANSFORM_ROT: " << o->getTransform()->getRotate() << "\n";
	py::print("saving active");
	if (o->getTransform()->isActive()) {
		myFile << "TRANSFORM_ACT: TRUE" << "\n";
	}
	else {
		myFile << "TRANSFORM_ACT: FALSE" << "\n";
	}
	myFile.close();
	return s + ".txt";
}

GameObject* FileManager::loadGameObject(std::string fileName, int globalID) {
	std::ifstream myFile(fileName);
	std::string line;
	GameObject *loadedObject = new GameObject(globalID);
	AudioManager *audio = new AudioManager();
	ImageComponent *image = new ImageComponent();
	int animFrames;
	int spriteWidth;
	int spriteHeight;
	int frameRate;
	bool shouldAnim;
	TextComponent *text = new TextComponent();
	Collider *collider = new Collider();
	float colliderX;
	float colliderY;
	float colliderW;
	float colliderH;
	Transform *transform = new Transform();


	if (myFile.is_open()) {
		while (getline(myFile, line)) {
			if (line.find("NAME:") != std::string::npos) {
				loadedObject->setName(line.substr(6));
			}
			if (line.find("ACTIVE: TRUE") != std::string::npos) {
				loadedObject->setActive(true);
			}
			if (line.find("ACTIVE: FALSE") != std::string::npos) {
				loadedObject->setActive(false);
			}
			if (line.find("MUSIC:") != std::string::npos) {
				loadedObject->getAudioComponent()->loadMusic(line.substr(7));
			}
			if (line.find("SOUND:") != std::string::npos) {
				loadedObject->getAudioComponent()->loadSound(line.substr(7));
			}
			if (line.find("IMAGE:") != std::string::npos) {
				loadedObject->getImageComponent()->setImage(line.substr(7));
			}
			if (line.find("ANIM_FRAMES:") != std::string::npos) {
				animFrames = std::stoi(line.substr(13));
			}
			if (line.find("SPRITE_W:") != std::string::npos) {
				spriteWidth = std::stoi(line.substr(10));
			}
			if (line.find("SPRITE_H:") != std::string::npos) {
				spriteHeight = std::stoi(line.substr(10));
			}
			if (line.find("FRAME_RATE:") != std::string::npos) {
				frameRate = std::stoi(line.substr(12));
			}
			if (line.find("IMAGE:") != std::string::npos) {
				loadedObject->getImageComponent()->setImage(line.substr(7));
			}
			if (line.find("SHOULD_ANIM: TRUE") != std::string::npos) {
				shouldAnim = true;
			}
			if (line.find("SHOULD_ANIM: FALSE") != std::string::npos) {
				shouldAnim = false;
			}
			if (line.find("COLLIDER_X:") != std::string::npos) {
				colliderX = std::stof(line.substr(12));
			}
			if (line.find("COLLIDER_Y:") != std::string::npos) {
				colliderY = std::stof(line.substr(12));
			}
			if (line.find("COLLIDER_W:") != std::string::npos) {
				colliderW = std::stof(line.substr(12));
			}
			if (line.find("COLLIDER_H:") != std::string::npos) {
				colliderH = std::stof(line.substr(12));
			}
			if (line.find("TRANSFORM_X:") != std::string::npos) {
				loadedObject->getTransform()->setX(std::stof(line.substr(13)));
			}
			if (line.find("TRANSFORM_Y:") != std::string::npos) {
				loadedObject->getTransform()->setY(std::stof(line.substr(13)));
			}
			if (line.find("TRANSFORM_ROT:") != std::string::npos) {
				loadedObject->getTransform()->setRotate(std::stof(line.substr(15)));
			}
			if (line.find("TRANSFORM_ACT: TRUE") != std::string::npos) {
				loadedObject->getTransform()->setActive(true);
			}
			if (line.find("TRANSFORM_ACT: FALSE") != std::string::npos) {
				loadedObject->getTransform()->setActive(false);
			}
		}
		loadedObject->getCollider()->setColliderSize(colliderX, colliderY, colliderW, colliderH);
		loadedObject->getImageComponent()->setAnimationFrames(animFrames, spriteWidth, spriteHeight, frameRate, shouldAnim);
		myFile.close();
		return loadedObject;
	}
	else {
		
		std::cout << "ERROR: Could not find file with name " << fileName;
		return NULL;
	}

}

std::string FileManager::saveGame(std::map<int, GameObject*> objects, std::string fileName) {
	std::ofstream myFile;
	myFile.open(fileName + ".txt");
	std::map<int, GameObject*>::iterator it;
	unsigned int i = 1;
	py::print("in FileManager Save");
	for (it = objects.begin(); it != objects.end(); ++it) {
		// denoted with index number in case of duplicate names
		py::print("saving: " + it->second->getName());
		//py::print("image: " + it->second->getImageComponent()->getImageFile());
		myFile << saveGameObject(it->second, it->second->getName() + " (" + std::to_string(i) + ")") << "\n";
	}
	myFile.close();
	return fileName + ".txt";
}

std::map<int, GameObject*> FileManager::loadGame(std::string fileName) {
	std::ifstream myFile(fileName);
	std::string line;
	std::map<int, GameObject*> loadedObjects;
	int nextID = 0;

	if (myFile.is_open()) {
		while(getline(myFile, line)) {
			GameObject *obj = loadGameObject(line, nextID);
			loadedObjects.insert(std::pair<int, GameObject*>(nextID, obj));
			nextID++;
		}
	}
	return loadedObjects;
	myFile.close();
}




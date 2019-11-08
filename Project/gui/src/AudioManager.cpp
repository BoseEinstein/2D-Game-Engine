#include "../include/AudioManager.h"


AudioManager* audioInstance = 0;

AudioManager::AudioManager() {



}

AudioManager::~AudioManager() {
	//Frees memory allocated to sound assets when deconstructed
	Mix_FreeChunk(sound);
	Mix_FreeMusic(music);
	//Sets variables for storing assets to NULL to prevent unwanted access to memory
	sound = NULL;
	music = NULL;
}

void AudioManager::loadMusic(const std::string &fileName) {
	music = ResourceManager::getInstance()->loadMusic(fileName);
	_musicFile = fileName;
}

void AudioManager::loadSound(const std::string &fileName) {
	sound = ResourceManager::getInstance()->loadSound(fileName);
	_soundFile = fileName;
}

void AudioManager::playSound() {
	//Plays sound 
	Mix_PlayChannel(-1, sound, 0);

}

void AudioManager::playMusic(int repeat) {
	//Plays music
	Mix_PlayMusic(music, repeat);
}

std::string AudioManager::getMusicFile() {
	return std::string(_musicFile);
}

std::string AudioManager::getSoundFile() {
	return std::string(_soundFile);
}
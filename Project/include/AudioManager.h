#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include <stdio.h>
#include "ResourceManager.h"
#include <string>


class AudioManager {
public:

	/**
	CAN ACCESS THROUGH GAME ENGINE API
	Loads in the sound files to be used in the game.
	*/
	AudioManager();

	/**
	Release sound and music resources on this component
	*/
	~AudioManager();

	/**
	CAN ACCESS THROUGH GAME ENGINE API
	Play sound that is loaded onto the component.
	*/
	void playSound();

	/**
	CAN ACCESS THROUGH GAME ENGINE API
	Starts the music loop playing as defined by the data
	in the music pointer.
	*/
	void playMusic(int repeats);

	/**
	CAN ACCESS THROUGH GAME ENGINE API
	Load a music file onto this Audio componenet specified by the file at the loaction provided
	*/
	void loadMusic(const std::string &fileName);
	/**
	CAN ACCESS THROUGH GAME ENGINE API
	Load a sound file onto this Audio componenet specified by the file at the loaction provided
	*/
	void loadSound(const std::string &fileName);
	/**
	Get the file location of the music file loaded onto this object, empty string if there is none
	*/
	std::string getMusicFile();
	/**
	Get the file location of the music file loaded onto this object, empty string if there is none
	*/
	std::string getSoundFile();

private:
	Mix_Chunk *sound;
	Mix_Music *music;
	std::string _musicFile;
	std::string _soundFile;

};

#endif // !AUDIOMANAGER_H

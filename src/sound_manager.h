#pragma once
#include "../irrklang/include/irrKlang.h"
#include "../irrklang/include/ik_ISoundEngine.h"
#include "../../../include/aftr/Vector.h"
#include "Vector.h"

class sound_manager
{
public:
	static sound_manager* init();																					//create sound engine
	virtual void play_2d_sound(const char* sound_file, bool play_loop, bool start_puase, bool track);	//plays the 2d sound (background) by getting the sound file, determining if it plays through a loop, is playing, or a track
	virtual void play_3d_sound(const char* sound_file, Aftr::Vector pos, bool play_loop, bool start_puase, bool track); //same as 2d but uses a vector position as well
	virtual void stop_2d_sound();
	virtual void stop_3d_sound();
	static irrklang::vec3df position(const Aftr::Vector pos);											//postion of vec3d for 3d sound
	virtual irrklang::ISoundEngine* get_sound_eng();
	virtual void set_sound_eng(irrklang::ISoundEngine* sound_eng);
	virtual std::vector<irrklang::ISound*> get_2d_sound();
	virtual std::vector<irrklang::ISound*> get_3d_sound();


protected:
	static irrklang::ISoundEngine* sound_engine;
	std::vector<irrklang::ISound*> sound_2d;			//create 2d sound variable
	std::vector<irrklang::ISound*> sound_3d;			//create 3d sound variable
	
};
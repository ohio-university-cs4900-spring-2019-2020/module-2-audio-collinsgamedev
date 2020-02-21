#include "sound_manager.h"
#include <iostream>

irrklang::ISoundEngine* sound_manager::sound_engine = nullptr;

sound_manager* sound_manager::init()
{
	sound_manager* mng = new sound_manager();
	sound_engine = irrklang::createIrrKlangDevice();
	if (!sound_engine)
	{
		std::cout << "Couldn't initialize sound engine\n";
	}
	return mng;
}

void sound_manager::play_2d_sound(const char* sound_file, bool play_loop, bool start_puase, bool track)
{
	if (!sound_engine)
	{
		std::cout << "No engine found for 2d.\n";
	}
	sound_2d.push_back(sound_engine->play2D(sound_file, play_loop, start_puase, track));
}

void sound_manager::play_3d_sound(const char* sound_file, Aftr::Vector pos, bool play_loop, bool start_puase, bool track)
{
	if (!sound_engine)
	{
		std::cout << "No engine found for 3d.\n";
	}
	sound_3d.push_back(sound_engine->play3D(sound_file, position(pos), play_loop, start_puase, track));
}

void sound_manager::stop_2d_sound()
{
	if (sound_2d.empty())
		return;

	sound_2d.at(0)->stop();
	sound_2d.erase(sound_2d.begin());
}

void sound_manager::stop_3d_sound()
{
	if (sound_3d.empty())
		return;

	sound_3d.at(0)->stop();
	sound_3d.erase(sound_3d.begin());
}

irrklang::vec3df sound_manager::position(const Aftr::Vector pos)
{
	return irrklang::vec3df(pos.x, pos.y, pos.z);
}

irrklang::ISoundEngine* sound_manager::get_sound_eng()
{
	return this->sound_engine;
}

void sound_manager::set_sound_eng(irrklang::ISoundEngine* sound_eng)
{
	this->sound_engine = sound_eng;
}

std::vector<irrklang::ISound*> sound_manager::get_2d_sound()
{
	return this->sound_2d;
}

std::vector<irrklang::ISound*> sound_manager::get_3d_sound()
{
	return this->sound_3d;
}
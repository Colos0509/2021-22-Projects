#pragma once

#include <SDL_mixer.h>
#include <string>

class Music
{

public:

	enum class PlayLoop { PLAY_ONCE = 1, PLAY_ENDLESS = -1 };

	static bool Initialize();
	static void ShutDown();

	Music();

	bool Load(const std::string& filename);
	void Unload();

	void SetVolume(int volume);

	void Play(PlayLoop playLoop);
	void Pause();
	void Resume();
	void Stop();

private:

	Mix_Music* m_music;

};


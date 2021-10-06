#include <iostream>
#include "Sound.h"

Sound::Sound()
{
    m_sound = nullptr;
}

bool Sound::Load(const std::string& filename)
{
    m_sound = Mix_LoadWAV(filename.c_str());

    if (!m_sound)   //flag in case of something is wrong with loading the file
    {
        std::cout << "Error loading sound!" << std::endl;
        return false;
    }
    return true;
}

void Sound::Unload()
{
    Mix_FreeChunk(m_sound);
}

void Sound::SetVolume(int volume)
{
    Mix_VolumeMusic(volume);
}

void Sound::Play(int loop)
{
    if (Mix_PlayChannel(-1, m_sound, loop) == 1)
    {
        std::cout << "Error playing sound!" << std::endl;
    }
}

void Sound::Stop()   //I put this here for the footstep sounds. Used in player class, Update
{
     Mix_HaltChannel(-1);    
}

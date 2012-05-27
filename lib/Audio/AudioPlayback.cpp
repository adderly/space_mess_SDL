#include"AudioPlayback.h"

namespace AudioPlayback
{

Audio::Audio()
{
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);

    music = Mix_LoadMUS("resources/sound/sound.wav");
    effect = Mix_LoadWAV("resources/sound/tone.wav");
    if(music == NULL) saveLog("Fucking audio!");

}
Audio::Audio(const std::string name,const std::string location)
{
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
    addMusic(name,location);
}
void Audio::addMusic(const std::string name,const std::string location)
{
    Mix_Music* ms = Mix_LoadMUS(location.c_str());

    if(ms == NULL) return;
    else
    {
        try
        {
            songs.insert(std::pair<std::string,Mix_Music*>(name,ms));
        }
        catch(...)
        {
            saveLog("Could Not Load"+name+" at "+location);
        }
    }

}
void Audio::loadSound(const std::string name,const std::string location)
{
    Mix_Chunk* snd = Mix_LoadWAV(location.c_str());
    if(snd == NULL) return;
    else
    {
        try
        {
            effects.insert(std::pair<std::string,Mix_Chunk*>(name,snd));
        }
        catch(...)
        {
            saveLog("Could Not Load"+name+" at "+location);
        }
    }

}
void Audio::play()
{
    Mix_PlayMusic(music,-1);
}
void Audio::playSpecific(const std::string name)
{

}
void Audio::playEffect(const std::string name)
{
    Mix_PlayChannel(-1,effect,1);
}
void Audio::playEffect(Mix_Chunk* effect)
{
    Mix_PlayChannel(-1,effect,1);
}
void Audio::pause()
{
    Mix_PauseMusic();
}
void Audio::resume()
{
    Mix_RewindMusic();
}
void Audio::nextMusic() {}
void Audio::previousMusic() {}
void Audio::volumeUp() {}
void Audio::volumeDown() {}
void Audio::specificVolume(int desireVolume) {}
Audio::~Audio()
{
    delete (&music);
    delete (&effects);
    delete (&musicList);
    delete  (&current);
}

}


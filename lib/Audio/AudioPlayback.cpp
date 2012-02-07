#include"AudioPlayback.h"

Audio::Audio()
{
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
}
Audio::Audio(const std::string name,const std::string location)
{
}
void Audio::addMusic(const std::string name,const std::string location){}
void Audio::loadSound(const char* filename)
{
    music = Mix_LoadMUS("resources/sound/sound.wav");
    effect = Mix_LoadWAV("resources/sound/tone.wav");
}
void Audio::play()
{
    Mix_PlayMusic(music,-1);
}
void Audio::playSpecific(const std::string name){}
void Audio::playEffect(const std::string name)
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
void Audio::nextMusic(){}
void Audio::previousMusic(){}
void Audio::volumeUp(){}
void Audio::volumeDown(){}
void Audio::specificVolume(int desireVolume){}
Audio::~Audio()
{
    delete (&music);
    delete (&effects);
    delete (&musicList);
    delete  (&current);
}



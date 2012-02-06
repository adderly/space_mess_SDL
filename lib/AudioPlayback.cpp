#include"AudioPlayback.h"

Audio::Audio()
{
    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
}
void Audio::loadSound(const char* filename)
{
    music = Mix_LoadMUS("resources/sound.wav");
    effect = Mix_LoadWAV("resources/tone.wav");
}
void Audio::play()
{
    Mix_PlayMusic(music,-1);
}
void Audio::pause()
{
    Mix_Pause(-1);
}
void Audio::resume()
{
    Mix_Resume(-1);
}

Audio::~Audio()
{

}



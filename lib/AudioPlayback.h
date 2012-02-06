#include<SDL/SDL_mixer.h>
#include<vector>

class Audio
{
    Mix_Chunk* effect;
    Mix_Music* music;

    public:
        Audio();
        void loadSound(const char* filename);
        void play();
        void pause();
        void resume();
        ~Audio();
};



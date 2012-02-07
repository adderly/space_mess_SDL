#include<SDL/SDL_mixer.h>
#include<map>
#include<string>
#include<vector>


/*

*   When a action occurs in the game
*   it will called and asigned effect(sound)
*   ex. player shooting
*/

class Audio
{
    Mix_Chunk* effect;
    Mix_Music* music;

    std::map<std::string,Mix_Chunk*> songs; //Songs or something like it
    std::map<std::string,Mix_Chunk*> effects;
    std::vector<std::string> musicList; //for next and previous
    std::string current;

    //audio Configuration
    int volume;
    int frecuency;  //22050:22khz__44100:44.1khz
    int channel; //2:stereo...
    int size;


    public:
        Audio();
        Audio(const std::string name,const std::string location); //default song
        void addMusic(const std::string name,const std::string location);
        void loadSound(const char* filename);
        void play();
        void playSpecific(const std::string name); //inside the map
        void playEffect(const std::string name);
        void pause();
        void resume();
        void nextMusic();
        void previousMusic();
        void volumeUp();
        void volumeDown();
        void specificVolume(int desireVolume);
        ~Audio();
};



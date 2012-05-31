
#ifndef PLAYER
#define PLAYER
#include"Actors/Gun.h"
#include"ParticleGenerator.h"
#include"Audio/AudioPlayback.h"
namespace Actors
{

    using namespace AudioPlayback;
    typedef void (Audio::*play)();

    class Player
    {
        Gun *gun;
        ParticleGenerator* gen;
    public:
        play p;
        friend class ParticleGenerator;
        int movx;
        int movy;
        int movz;
        int x;
        int y;
        int width;
        int height;
        bool alive;
        void shoot();

        Player(ParticleGenerator* gen);
        ~Player();
    };
};
#endif


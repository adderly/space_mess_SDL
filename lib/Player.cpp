#include"Player.h"
 namespace Actors
{
    Player::Player(ParticleGenerator* g)
    {
        this->p = &Audio::play ;
        this->movx = 0;
        this->movy = 0;
        this->movz = 0;
        this->alive = true;
        this->width = 80;
        this->height = 45;
        this->x = 0;
        this->y = 0;
        gen = g;
        gun = new Gun();
    }
    void Player::shoot()
    {

        if(gun->ammoAmount > 0)
        {
            float color[] = {0,255,0};
            Particle* particle =  new Particle(x,y/2,-1,2,0.01,0,10.0,color);
            particle->setSize(7,4);
            gun->fire();
            gen->addParticle(particle);
        }

    }
    //void Player::shoot(Audio& ai,){}

    Player::~Player() {}
};

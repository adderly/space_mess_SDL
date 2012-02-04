#include<cstdlib>
#include<iostream>
#include<vector>

//typedef Particle Particle;

#ifndef Particle
    #include"Particle.h"
#endif

class ParticleGenerator
{

    int particleCount;

    public:
    friend class render;
    std::vector<Particle*> particles;
    ParticleGenerator();
    void createParticles(int num);
    void evolveParticles();
    std::vector<Particle*> &getParticles();
    ~ParticleGenerator();

};

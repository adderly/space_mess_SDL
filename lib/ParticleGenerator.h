#include<cstdlib>
#include<iostream>
#include<vector>
#include<math.h>

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
    void addParticle(int x,int y, int z,float speedx,float speedy,float speedz,float life,float *color);
    void addParticle(Particle* newone);
    void evolveParticles();
    std::vector<Particle*> &getParticles();
    ~ParticleGenerator();

};

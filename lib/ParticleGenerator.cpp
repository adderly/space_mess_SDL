#include"ParticleGenerator.h"

ParticleGenerator::ParticleGenerator(){}
void ParticleGenerator::createParticles(int amount)
{
    float colorv[] = {255.0,255.0,0.0};
    for(int n = 0; n< amount;n++)
    {
        Particle* p = new Particle(10,10,-1,0.15*n,0.01*n,0.0,10.0,colorv);
        p->setSize(5,5);
        particles.push_back(p);
    }
}
void ParticleGenerator::evolveParticles()
{
    for(int amount = 0; amount < particles.size();amount++)
    {
        particles[amount]->autoEvolve();
       // std::cout<<particles[amount]->pos_x;
    }
}
std::vector<Particle*> &ParticleGenerator::getParticles()
{
    return particles;
}
ParticleGenerator::~ParticleGenerator(){}



#include"ParticleGenerator.h"

ParticleGenerator::ParticleGenerator()
{

}
void ParticleGenerator::addParticle(Particle* newone)
{
    particles.push_back(newone);
}
void ParticleGenerator::addParticle(int x,int y, int z,float speedx,float speedy,float speedz,float life,float *color)
{
    Particle* p = new Particle(x,y,z,speedx,speedy,speedz,10.0,color);
    p->setSize(6,2);
    particles.push_back(p);
}
void ParticleGenerator::genParticlesAt(int x, int y,int z,int amount)
{

    float XNumber= 0;
    float YNumber= 0;


    float colorv[] = {255.0,255.0,0.0};
    for(int n = 0; n< amount; n++)
    {
        if(rand()/rand() > 45000)
        {
            XNumber= 0.0005-(rand()%100/22.5);
            YNumber= 0.0005-(rand()%100/9);
        }
        else
        {

            XNumber= 0.0005-(rand()%100/12.5);
            YNumber= 0.0005-(rand()%100/20);
        }


        Particle* p = new Particle(x,y,z,(n%amount*XNumber)/5,n%amount*YNumber/5,0.0,10.0,colorv);
        p->setSize(4,2);
        particles.push_back(p);

    }
}
void ParticleGenerator::createParticles(int amount)
{
    int counter = 0;



    float XNumber= 0;
    float YNumber= 0;


    float colorv[] = {255.0,255.0,0.0};
    for(int n = 0; n< amount; n++)
    {
        if(rand()/rand() > 45000)
        {
            XNumber= 0.0005-(rand()%100/22.5);
            YNumber= 0.0005-(rand()%100/9);
        }
        else
        {

            XNumber= 0.0005-(rand()%100/12.5);
            YNumber= 0.0005-(rand()%100/20);
        }


        Particle* p = new Particle(350,240,-1,(n%amount*XNumber)/5,n%amount*YNumber/5,0.0,10.0,colorv);
        p->setSize(4,2);
        particles.push_back(p);

    }
}
void ParticleGenerator::evolveParticles()
{

    for(int amount = 0; amount < particles.size(); amount++)
    {

        particles[amount]->autoEvolve();
        // std::cout<<particles[amount]->pos_x;
    }
}
std::vector<Particle*> &ParticleGenerator::getParticles()
{
    return particles;
}
ParticleGenerator::~ParticleGenerator() {}



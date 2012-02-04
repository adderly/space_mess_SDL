#include"Particle.h"

Particle::Particle()
{
    this->alive = true;
}

Particle::Particle(int x,int y, int z,float speedx,
                   float speedy,float speedz,float life ,float *color)
{
    pos_x = x;
    pos_y = y;
    pos_z = z;
    speed_x = speedx;
    speed_y = speedy;
    speed_z = speedz;
    lifetime = life;
    colorv = color;

}

void Particle::autoEvolve()
{
    pos_x+= speed_x;
    pos_y+= speed_y;
    pos_z+= speed_z;

}

void Particle::VariateSpeed(int x,int y,int z)
{
     speed_x = x;
     speed_y = y;
     speed_z = z;
}
Particle::~Particle(){}



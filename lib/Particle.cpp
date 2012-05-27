#include"Particle.h"

Particle::Particle()
{
    this->alive = true;
    width = 2;
    height = 2;
    x_max = 0;
    y_max = 0;
    width = 2;
    height = 2;
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
    x_max = 0;
    y_max = 0;
}

void Particle::autoEvolve()
{
    if(x_max == 0)
    {
        pos_x+= speed_x;
        pos_y+= speed_y;
        pos_z+= speed_z;

    }
    else
    {

        if(pos_x+pos_y < x_max) pos_x += speed_x;
        if(pos_x+pos_y > x_max) pos_x -= speed_x;
        if(pos_x+pos_y > y_max) pos_y -= speed_y;
        if(pos_x+pos_y < y_max) pos_y += speed_y;




//       else
//       {
//           pos_x+= speed_x;
//            pos_y+= speed_y;
//            pos_z+= speed_z;
//       }
    }

}

void Particle::VariateSpeed(int x,int y,int z)
{
    speed_x = x;
    speed_y = y;
    speed_z = z;
}
Particle::~Particle() {}



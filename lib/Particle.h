#ifndef PARTICLE
#define PARTICLE

class Particle
{
public:
    float lifetime;
    float* colorv;
    float height,width;
    float pos_x,pos_y,pos_z;
    float x_max,y_max;
    float speed_x,speed_y,speed_z;
    bool alive;
    Particle();
    Particle(int x,int y, int z,float speedx,float speedy,float speedz,float life,float *color);

    void setSize(float w,float h)
    {
        width = w;
        height=h;
    };
    void VariateSpeed(int x,int y, int z);//for accelerating the particle
    void autoEvolve();
    ~Particle();
};

#endif

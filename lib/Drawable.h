#include"Draw.h"
#include"../utils/Log.h"

#ifndef DRAWABLE
#define DRAWABLE

class Drawable:Draw
{
    public:
    float x,y,width,height;
    float color[4];
    SDL_Surface* ParentBackground,*background;
    Drawable(float X,float Y,float WIDTH,float HEIGHT)
    {
        this->x = X;
        this->y = Y;
        this->width = WIDTH;
        this->height = HEIGHT;
        color[0] = 1.0;
        color[1] = 0.0;
        color[2] = 0.0;
        color[3] = 0.0;
    }
    void setBounds(float x,float y,float w,float h)
    {
        this->x = x;
        this->y = y;
        this->width = w;
        this->height;
    }
    void setLocation(float x,float y)
    {
        this->x = x;
        this->y = y;
    }
    void setSize(float w,float h)
    {
        this->width = w;
        this->height = h;
    }
    void setColor(float* color)
    {
        if(sizeof(color)/sizeof(float) == sizeof(float)*4)
        {
        this->color[0] = *(color);
        this->color[1] = *(color++);
        this->color[2] = *(color++);
        this->color[3] = *(color++);
        saveLog("ont");
        }
    }
    void setColor(float r,float g,float b,float a)
    {
        this->color[0] = r;
        this->color[1] = g;
        this->color[2] = b;
        this->color[3] = a;
    }
    void setBackground(SDL_Surface* src)
    {
        this->background = src;
    }
    void setParentBackground(SDL_Surface*  bck)
    {
         this->ParentBackground = bck;
    }
    SDL_Surface* getBackgroung()
    {
        return this->background;
    }
    SDL_Surface* getParentBackground()
    {
        return this->ParentBackground;
    }
    virtual void draw()=0;
};
#endif


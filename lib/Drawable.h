#include"Draw.h"
#include"Interfaces/GeometricElement.h"
#include"Log.h"
#include"EventInterface.h"
#include<SDL/SDL.h>


#ifndef DRAWABLE
#define DRAWABLE

/*

    This class should countain the necesary stuff, for drawing a element
    and handle it in the 'drawing space'
*/

class Drawable:Draw, public eventSignals,public GeometricElement
{
public:
    bool isContainer;

    SDL_Surface* ParentBackground,*background;
    Drawable(float X,float Y,float WIDTH,float HEIGHT):eventSignals(),GeometricElement()
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
    void setBounds(float x,float y,float w,float h,float z = 0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->width = w;
        this->height;
    }
    void setLocation(float x,float y,float z = 0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
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

    /*Events*/

    virtual void f_clicked();
    virtual void f_rightclicked();
    virtual void f_selected();
    virtual void f_mouseover();
    virtual void f_drag();
    virtual void f_drop();
    virtual void check();


    virtual void draw()=0;
};
#endif


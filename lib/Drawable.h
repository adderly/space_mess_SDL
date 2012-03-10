

#ifndef DRAWABLE
#define DRAWABLE

class Drawable
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
        color[0] = 255;
        color[1] = 0.0;
        color[2] = 0.0;
        color[3] = 0.0;
    }
    void setParentBackground(SDL_Surface*  bck){ this->ParentBackground = bck;}
    SDL_Surface* getParentBackground(){return this->ParentBackground;}
    virtual void draw()=0;
};
#endif


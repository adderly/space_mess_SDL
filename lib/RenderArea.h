#include"Interfaces/GeometricElement.h"
#include"videoutil.h"

#ifndef RENDERAREA
#define RENDERAREA
/*

*/
class RenderArea: public GeometricElement
{
    bool blocked;//you can't change it properties width,height
    float *screen_x,*screen_y,*screen_width,*screen_height;
    int screen_bpp;
public:
    RenderArea()
     {
         loadSettings();
         screen_x = &x;
         screen_y = &y;
         screen_width = &width;
         screen_height = &height;
         screen_bpp = bpp;
         setBounds(0,0,settings_width,settings_height);
     }
    int getScreenBpp()
    {
        return this->screen_bpp;
    }
    float getScreenWidth()
    {
        return *this->screen_width;
    }
    float getScreenHeight()
    {
        return *this->screen_height;
    }
    bool getIsBlocked()
    {
        return this->blocked;
    }
    void setIsBlocked(bool what)
    {
        this->blocked = what;
    }
};


#endif




#include"Interfaces/GeometricElement.h"

#ifndef RENDERAREA
#define RENDERAREA

class RenderArea: public GeometricElement
{
    bool blocked;//you can't change it properties width,height
    public:

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




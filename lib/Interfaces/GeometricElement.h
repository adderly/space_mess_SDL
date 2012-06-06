#ifndef GEOMETRICELEMENT
#define GEOMETRICELEMENT

class GeometricElement
{
public:
    bool isQuad;
    bool defaultColor;
    float color[4];
    float selectedColor[4];
    float x,y,z,width,height;
    GeometricElement() {}

    void setBounds(float x,float y,float w,float h,float z = 0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->width = w;
        this->height = h;
    }
    float* getVertexPointer()
    {
        float coords[] = {x,y,
                          x+width,y,
                          x+width,y+height,
                          x,y+height};
        return coords;
    }
    void setIsDefaultColor(bool what)
    {
        this->defaultColor = what;
    }
    bool getIsDefaulColor()
    {
        return this->defaultColor;
    }
    virtual void setIsQuad(bool what)
    {
        this->isQuad =  what;
    }
    virtual bool getIsQuad()
    {
        return this->isQuad;
    }
};

#endif




#ifndef GEOMETRICELEMENT
#define GEOMETRICELEMENT

class GeometricElement
{
     public:
     float color[4];
     float x,y,z,width,height;
     GeometricElement(){}
      void setBounds(float x,float y,float w,float h,float z = 0)
        {
            this->x = x;
            this->y = y;
            this->width = w;
            this->height;
        }
};

#endif



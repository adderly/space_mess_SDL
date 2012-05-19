#include <vector>
#include "Drawable.h"


#ifndef GRID
#define GRID

class Grid: public Drawable
{
    float _x,_y,_z;
    float _width,_height;


    public:
    Grid();
    ~Grid();
    void addToGrid(Drawable);


};

#endif

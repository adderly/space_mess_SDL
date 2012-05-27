#include"Draw.h"

#ifndef DRAWER
#define DRAWER

class Drawer: public Draw
{
public:
    Drawer();
    ~Drawer();
    virtual void draw() = 0;
};

#endif


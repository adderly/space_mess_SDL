#include"Draw.h"
#include"Drawable.h"

#ifndef DRAWER
#define DRAWER

class Drawer: public Draw
{
public:
    Drawer();
    ~Drawer();
    virtual void draw() = 0;
 //   virtual void drawContainer(Drawable *) = 0;
};

#endif


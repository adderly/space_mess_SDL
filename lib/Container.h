#include <vector>
#include "Drawable.h"

#ifndef CONTAINER
#define CONTAINER

class Container:public Drawable
{
    vector<Drawable*> items;
public:
    Container();
    Container(vector<Drawable*>);
    void addItem(Drawable*);
    void removeItem(Drawable*);
    virtual void draw();
    ~Container();
};
#endif

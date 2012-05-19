#include<vector>
#include<map>
#include"Drawable.h"

#ifndef DRAWER
#define DRAWER

/*
    class for drawing all the element,added to panels and etc
*/
class Drawer
{
    /*
        this map will have all the drawables for rendering map<zindex,vectorofelementsinthezindex>
    */
    std::map<float,std::vector<Drawable*> > _toRender;
    std::map<float,std::vector<Drawable*> >::iterator _toRenderIterator;

    public:
    Drawer();
    virtual ~Drawer();
    virtual void draw();


};

#endif

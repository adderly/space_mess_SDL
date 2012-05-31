

#ifndef CONTAINER
#define CONTAINER

#include <vector>
#include "Drawable.h"
#include"Render.h"
namespace Graphics
{

    class Container:public Drawable
    {

    public:
       vector<Drawable*> items;
        Container();
        Container(vector<Drawable*>);
        virtual void addItem(Drawable*);
        virtual void removeItem(Drawable*);
        virtual void draw();
          /*Events*/

        virtual void f_clicked(){}
        virtual void f_rightclicked(){}
        virtual void f_selected(){}
        virtual void f_mouseover(){}
        virtual void f_drag(){}
        virtual void f_drop(){}
        virtual void check(){}

        ~Container();
    };
}

#endif

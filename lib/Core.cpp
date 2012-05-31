#include "Core.h"

Core::Core():Render()
{


    Drawable* first = new Drawable(19,10,350,200);
    first->isQuad = false;
    first->setColor(1,1,0,0);
    first->setClickCallBack(sigc::mem_fun(this,&Core::test));

    Container *cont = new Container();
    cont->setBounds(0,0,450,405);
    cont->isQuad = true;
    cont->addItem(first);
    cont->setColor(1,0,0,0);

    addDrawable(cont);
}
int Core::run()
{

}
void Core::test()
{
       exit(-1);
}

Core::~Core(){}


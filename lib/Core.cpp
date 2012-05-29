#include "Core.h"

Core::Core():Render()
{
    Drawable* first = new Drawable(0,0,500,200);
    first->setClickCallBack(sigc::mem_fun(this,&Core::test));
    addDrawable(first);
}
int Core::run()
{

}
void Core::test()
{
       exit(-1);
}

Core::~Core(){}


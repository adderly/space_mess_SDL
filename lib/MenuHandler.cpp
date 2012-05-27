#include"MenuHandler.h"




namespace Graphics
{

MenuHandler::MenuHandler()
{

}
void MenuHandler::loadDefaults()
{
    // mainmenu =  new Menu(width,height,450,270);

}
void MenuHandler::check(SDL_Event* e)
{
    if(mainmenu->visible)
    {
        mainmenu->check(*e);
        current = mainmenu;
    }
    else if(initmenu->visible)
    {
        initmenu->check(*e);
        current = initmenu;
    }
    else if(pausemenu->visible)
    {
        pausemenu->check(*e);
        current = pausemenu;
    }
    else
    {
        for(it= menus.begin(); it != menus.end(); it++)
        {
            (*it)->check(*e);
            current = (*it);
        }
    }
}
void MenuHandler::closeActive()
{
    current->visible = false;
}
void MenuHandler::gotoMain()
{
    closeActive();
    mainmenu->visible = true;
}
void MenuHandler::switchTo()
{

}
MenuHandler::~MenuHandler() {}

}

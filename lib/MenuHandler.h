#include"Menu.h"

class MenuHandler
{
    enum menus:bool
    {
        MAINMENU=false,PAUSEMENU = false,INIT_MENU = false
    };
    public:
    Menu *mainmenu,*pausemenu,*current;
    MenuHandler();
    void loadDefaults();
    void check(SDL_Event* e));
    void switchTo();
    void gotoMain();
    void closeActive();
    void setMainMenu(Menu* menu){mainmenu = menu;}
    void setPauseMenu(Menu* menu){pausemenu = menu;}
    ~MenuHandler();
};

MenuHandler::MenuHandler()
{

}
void MenuHandler::loadDefaults()
{
    mainmenu =  new Menu(width,height,450,270);

}
void MenuHandler::check(SDL_Event* e)
{
    current->check(e);
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
MenuHandler::~MenuHandler(){}


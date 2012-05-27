#include"Menu.h"

namespace Graphics
{
#ifndef MHandler
#define MHandler
class MenuHandler
{
    list<Menu*> menus;
    list<Menu*>::iterator it;


public:

enum menus:
    bool
    {
        MAINMENU=false,PAUSEMENU = false,UTILS_MENU = false
    };

    Menu *mainmenu,*pausemenu,*initmenu,*current;
    MenuHandler();
    void loadDefaults();
    void check(SDL_Event* e);
    void switchTo();
    void gotoMain();
    void closeActive();
    void setMainMenu(Menu* menu)
    {
        mainmenu = menu;
    }
    void setPauseMenu(Menu* menu)
    {
        pausemenu = menu;
    }
    ~MenuHandler();
};
#endif
}

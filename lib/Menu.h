#include"../utils/TextRender.h"
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_opengl.h>
#include<string>
#include<list>
#include"Drawable.h"
#include"MenuOption.h"
#include"EventInterface.h"
#include<sstream>
#include"videoutil.h"
#include"../utils/Log.h"
#include"../utils/keys.h"
#include"../utils/ImageManager.h"
#include"../utils/stringfunctions.h"
#include"sigc++/sigc++.h"




namespace Graphics
{

/*
 This would be an specifier for the way or ordering items in a menu
*/
#ifndef GRIDO
#define GRIDO
typedef struct
{
enum layout:
    bool {}; //FlowLayout,GridLayout,freeLayout

    float spacing;
    int columns ;
} GridOptions;
#endif
//#ifndef Panel
//#define Panel
//class Panel:public Drawable,public EInterface
//{
//
//};
//#endif
#ifndef MENU
#define MENU


class Menu:public Drawable,public EInterface, public sigc::trackable
{
    bool dragging;
    bool someOptionEnabled;//enhance event checking
    SDL_Surface* background;
    SDL_Event *event;
    MenuOption *exit,*back;
    std::list<MenuOption*> options;
    std::list<MenuOption*>::iterator it;
    GridOptions gridoptions;
    Images::ImageManager imgr;
    Images::Text txt;

public:
    friend class Drawable;
    sigc::signal<void> detected;
    bool visible;
    Menu();
    Menu(float parentWidth,float parentHeight,float,float);
    Menu(float X,float Y,float WIDTH,float HEIGHT,std::list<MenuOption*> optns,GridOptions gridoptns):Drawable(10,10,10,10)
    {
        this->x = X;
        this->y = Y;
        this->width = WIDTH;
        this->height = HEIGHT;
        this->options = optns;
        this->gridoptions = gridoptns;
    }
    Menu(std::list<MenuOption*> optns,GridOptions gridoptns):Drawable(10,10,10,10)
    {
        this->options=optns;
        this->gridoptions = gridoptns;
    }

    void init();
    void setUpItems();
    void check(SDL_Event &event);
    void check();
    void draw();
    inline void mouseOver();
    inline void mouseDown();
    inline void mouseUp();
    inline void drag();
    void setUpOption(MenuOption* opt);
    void addOption(MenuOption* opt);
    void setBackground(SDL_Surface* surface)
    {
        this->background = surface;
    }
    void setEvent(SDL_Event &e)
    {
        this->event = &e;
    }
    void setOptions(std::list<MenuOption*> optns)
    {
        this->options = optns;
    }
    void setGrid(GridOptions grid)
    {
        this->gridoptions = grid;
    }
    void setVisible(bool value);
    void setExitOption(MenuOption*);
    void setBackOption(MenuOption*);
    SDL_Surface* getBackground()
    {
        return this->background;
    }
    std::list<MenuOption*> getOptions()
    {
        return this->options;
    }
    GridOptions getGrid()
    {
        return this->gridoptions;
    }


    ~Menu();
};
#endif
}

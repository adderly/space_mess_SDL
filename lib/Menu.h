#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_opengl.h>
#include<string>
#include<list>
#include"Drawable.h"
#include<sstream>
#include"videoutil.h"
#include"../utils/Log.h"
#include"../utils/keys.h"
#include"../utils/TextRender.h"
#include"../utils/ImageManager.h"
#include"../utils/stringfunctions.h"

/*
    A menu have options, and this options have attributes.
    To make it clear an option of a menu may contain a pointer
    to a function
*/
/*  OPtion to be contained Inside A menu*/
#ifndef MENUOPTION
#define MENUOPTION
typedef class MenuOption
{
    public:
    SDL_Surface *background;
    unsigned int b;
    float width,height,x,y;
    float defaultwidth,defaultheight;
    std::string text;
    bool enable;


    //callbacks
    void (*vfunc)();
    void (*func)(int);
    void (*keyDown)(int);
    void (*keyUp)(int);

    MenuOption()
    {
        defaultheight =70;
        defaultwidth =120;
        this->enable = false;
    }
    MenuOption(float x,float y,float w,float h)
    {
        this->x=x;
        this->y=y;
        this->width=w;
        this->height=h;
        this->enable = false;
    }

};
#endif

#ifndef BUTTON
#define BUTTON
class Button
{

};
#endif
#ifndef CHECKBOX
#define CHECKBOX
class CheckBox
{

};
#endif
/*
 This would be an specifier for
*/

typedef struct
{
    enum layout:bool{};
    float spacing;
    int columns ;
}GridOptions;

/*  The Menu Extends Drawable Cause it would drawItself*/
class EInterface
{
    public:
    virtual void check()=0;
    virtual void check(SDL_Event&)=0;
    virtual void inline mouseOver() = 0;
    virtual void inline mouseDown() = 0;
    virtual void inline mouseUp() = 0;
    virtual void inline drag() = 0;
};
#ifndef MENU
#define MENU

class Menu:public Drawable,public EInterface
{
    bool dragging;
    bool someOptionEnabled;//enhance event checking
    SDL_Surface* background;
    SDL_Event *event;
    MenuOption *exit,*back;
    std::list<MenuOption*> options;
    std::list<MenuOption*>::iterator it;
    GridOptions gridoptions;
    ImageManager imgr;
    Text txt;

    public:
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
    void addOption(MenuOption* opt);
    void setBackground(SDL_Surface* surface){this->background = surface;}
    void setEvent(SDL_Event &e){this->event = &e;}
    void setOptions(std::list<MenuOption*> optns){ this->options = optns;}
    void setGrid(GridOptions grid){ this->gridoptions = grid;}
    void setVisible(bool value);
    void setExitOption(MenuOption*);
    void setBackOption(MenuOption*);
    SDL_Surface* getBackground(){return this->background;}
    std::list<MenuOption*> getOptions(){return this->options;}
    GridOptions getGrid(){return this->gridoptions;}


    ~Menu();
};
#endif

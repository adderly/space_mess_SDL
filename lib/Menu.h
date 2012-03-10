#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_opengl.h>
#include<string>
#include<list>
#include"Drawable.h"
#include<sstream>
#include"../utils/Log.h"
#include"../utils/keys.h"
#include"../utils/TextRender.h"

/*
    A menu have options, and this options have attributes.
    To make it clear an option of a menu may contain a pointer
    to a function
*/
/*  OPtion to be contained Inside A menu*/
#ifndef MENUOPTION
#define MENUOPTION
typedef struct MenuOption
{
    public:
    MenuOption(){}
    SDL_Surface *background;
    float width,height,x,y;
    std::string text;
    bool enable;
    void (*func)();

};
#endif


/*
 This would be an specifier for
*/

typedef struct
{
    float spacing;
    int columns ;
}GridOptions;

/*  The Menu Extends Drawable Cause it would drawItself*/
class EInterface
{

    public:
    virtual void check()=0;
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
    SDL_Surface* background;
    SDL_Event *event;
    std::list<MenuOption*> options;
    std::list<MenuOption*>::iterator it;
    GridOptions gridoptions;
    Text txt;
    public:
    bool visible;
    void init();
    void setUpItems();
    void check();
    void draw();
    inline void mouseOver();
    inline void mouseDown();
    inline void mouseUp();
    inline void drag();
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
    void setBackground(SDL_Surface* surface){this->background = surface;}
    SDL_Surface* getBackground(){return this->background;}
    void setEvent(SDL_Event &e){this->event = &e;}
    void setOptions(std::list<MenuOption*> optns){ this->options = optns;}
    std::list<MenuOption*> getOptions(){return this->options;}
    void setGrid(GridOptions grid){ this->gridoptions = grid;}
    GridOptions getGrid(){return this->gridoptions;}
    void setVisible(bool value){ this->visible = value;}
    ~Menu();
};
#endif

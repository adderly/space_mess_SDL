#include<SDL/SDL.h>
#include"Log.h"
#include"keys.h"

#ifndef TRIGGERER
#define TRIGGERER

class EventTriggerer
{

    /*
// TODO (moisex#1#): The events Should be able to be masked.\
\
Example: Forward player action, could be triggered by any key configured by the user.

    */
    int mouse_x,mouse_y;
public:
    bool lock_eventcheck;
    EventTriggerer(){}
    void setMousePosition(int x,int y)
    {
        this->mouse_x = x;
        this->mouse_y = y;
    }
    int getMouseX(){ return this->mouse_x;}
    int getMouseY(){ return this->mouse_y;}
   virtual inline void check() = 0 ;
   virtual inline void check(SDL_Event&) = 0;
   virtual inline void trigger() = 0;
   virtual inline void checkMouseDown(SDL_Event&) = 0;
   virtual inline void checkMouseUp(SDL_Event&) = 0;
   virtual inline void checkKeyUp(SDL_Event&) = 0;
   virtual inline void checkKeyDown(SDL_Event&) = 0;


};

#endif


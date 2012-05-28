#include<SDL/SDL.h>
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
    SDL_Event event;
public:
    EventTriggerer();
    EventTriggerer(SDL_Event);
    ~EventTriggerer();
    void check();
    void check(SDL_Event&);
    void trigger();
};

#endif


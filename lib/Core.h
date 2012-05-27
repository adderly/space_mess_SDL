#include"Render.h"
#include"EventTriggerer.h"

#ifndef CORE
#define CORE

/*
    Theorically this would control interactions Drawing,
    and handle the flow
*/

class Core
{
// TODO (moisex#1#): Link The Event,Drawing with the core.
    SDL_Event event;
    EventTriggerer eventTrigger;
    Graphics::Render render;//draws

public://drawing,events
    Core();
    ~Core();
    void run();
};

#endif




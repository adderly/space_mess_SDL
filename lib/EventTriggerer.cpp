#include"EventTriggerer.h"

EventTriggerer::EventTriggerer()
{

}
EventTriggerer::EventTriggerer(SDL_Event e)
{
    switch(e.key.keysym.sym)
    {
        case SDLK_ESCAPE:
            Running = false;
            break;
        default:
        break;
    }
}
EventTriggerer::~EventTriggerer(){}
void EventTriggerer::check()
{

}
void EventTriggerer::check(Sdl_Event e)
{

}



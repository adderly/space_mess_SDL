#include"EventTriggerer.h"

EventTriggerer::EventTriggerer()
{

}
EventTriggerer::EventTriggerer(SDL_Event e)
{

}
EventTriggerer::~EventTriggerer(){}
void EventTriggerer::check()
{


}
void EventTriggerer::check(SDL_Event &e)
{
    while(SDL_PollEvent(&e))
    {
            if(e.type == SDL_QUIT) Running = false;

            switch(e.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    Running = false;
                    break;
                default:
                break;
            }
            }
}



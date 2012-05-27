#include"EventHandler.h"


EventHandler::EventHandler(SDL_Event* event)
{
    this->event =  event;
}
void EventHandler::check()
{
    while(SDL_PollEvent(event))
    {
        if(event->type == SDL_QUIT) Running = false;

        if (event->type == SDL_MOUSEMOTION)
        {

        }

        if(event->type == SDL_MOUSEBUTTONDOWN)
        {
            switch(event->button.button)
            {
            case SDL_BUTTON_LEFT:
                MOUSE_LCLICK = true;
                //shut();
                break;
            case SDL_BUTTON_RIGHT:
                // music->playEffect("sdfsd");
                MOUSE_RCLICK = true;
                break;
            case SDL_BUTTON_MIDDLE:
                MOUSE_MCLICK = true;
                break;
            case SDL_BUTTON_X1:
                break;
            case SDL_BUTTON_X2:
                break;
            default:
                break;
            }
        }
        if(event->type == SDL_MOUSEBUTTONUP)
        {
            switch(event->button.button)
            {
            case SDL_BUTTON_LEFT:
                MOUSE_LCLICK = false;
                //shut();
                break;
            case SDL_BUTTON_RIGHT:
                MOUSE_RCLICK = false;
                break;
            case SDL_BUTTON_MIDDLE:
                MOUSE_MCLICK = false;
                break;
            case SDL_BUTTON_X1:
                break;
            case SDL_BUTTON_X2:
                break;
            default:
                break;
            }
        }


        if(event->type == SDL_KEYDOWN)
        {
            switch(event->key.keysym.sym)
            {
            case SDLK_RIGHT:
                p_right = true;
                break;
            case SDLK_LEFT:
                p_left = true;
                break;
            case SDLK_UP:
                p_up = true;
                break;
            case SDLK_DOWN:
                p_down = true;
                break;
            case SDLK_p:
                //   music->play();
                break;
            case SDLK_r:
                // music->resume();
                break;
            case SDLK_s:
                // music->pause();
                break;
            default:
                break;
            }
        }
        if(event->type == SDL_KEYUP)
        {
            switch(event->key.keysym.sym)
            {
            case SDLK_RIGHT:
                p_right = false;
                break;
            case SDLK_LEFT:
                p_left = false;
                break;
            case SDLK_UP:
                p_up = false;
                break;
            case SDLK_DOWN:
                p_down = false;
                break;
            case SDLK_ESCAPE:
                Running = false;
                break;
            case SDLK_F12:
                //rend.setFullScreen();
                break;
            default:
                break;
            }
        }
    }
}

EventHandler::~EventHandler() {}


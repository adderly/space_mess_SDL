#include"Game.h"

Game::Game():Render()
{
    loadSettings();
}
void Game::movePlayers()
{
    if(p_right)
    {
        x+=2;
        player->x++;
    }
    if(p_left)
    {
        x-=2;
        player->x--;
    }
    if(p_up)
    {
        y-=2;
        player->y++;
    }
    if(p_down)
    {
        y+=2;
        player->y--;
    }
    if(MOUSE_LCLICK)
    {
        player->shoot();
    }

}

void Game::MainLoop()
{

    while(Running)
    {
        std::stringstream t;
        std::string title;


        movePlayers();
        checkEvent();
        draw();
        SDL_GL_SwapBuffers();

        //std::cout<<SDL_GetError()<<std::endl;
        //saveLog("error",SDL_GetError());

        t << "Event: (" << event.motion.x << "," << event.motion.y << ") ";
        t << "Player: (" << player->x << "," << player->y << ")";
        title = t.str();
        SDL_WM_SetCaption(title.c_str(), 0);

        if(1000/FPS > SDL_GetTicks()-start)
            SDL_Delay(1000/FPS>SDL_GetTicks()-start);

    }
    SDL_Quit();
}
void Game::checkEvent()
{
    while(SDL_PollEvent(&event))
    {

//        if(menu->visible)
//        {
//            menu->check(event);
//        }
        if(event.type == SDL_QUIT) Running = false;
        {
            if(event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
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
                    music->play();
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
            if(event.type == SDL_KEYUP)
            {
                switch(event.key.keysym.sym)
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
                    Paused = false;
                    break;
                }
            }

            if(event.type == SDL_MOUSEMOTION)
            {
                if(event.type == SDL_MOUSEBUTTONDOWN)
                {
                    switch(event.button.button)
                    {
                    case SDL_BUTTON_LEFT:
                        MOUSE_LCLICK = true;

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
                if(event.type == SDL_MOUSEBUTTONUP)
                {
                    switch(event.button.button)
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



            }

        }

    }

}
void Game::setTitle(int w,int h)
{
    std::stringstream t2;
    std::string title2;

    t2 << x<<"   "<<y;
    title2 = t2.str();
    SDL_WM_SetCaption(title2.c_str(), 0);
}
Game::~Game()
{

}




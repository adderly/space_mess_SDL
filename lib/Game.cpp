#include"Game.h"

Game::Game():render()
{
    isRunning = true;
}
void Game::movePlayers()
{
        if(right) rend.x++;
        if(left)  rend.x--;
        if(up) rend.y--;
        if(down) rend.y++;

//        if(right) player.x++;
//        if(left)  player.x--;
//        if(up) player.y++;
//        if(down) player.y--;
}

void Game::MainLoop()
{
    while(isRunning)
    {
      std::stringstream t;
      std::string title;

        movePlayers();
        checkEvents();
        rend.draw();
        std::cout<<SDL_GetError();
        SDL_GL_SwapBuffers();



        t << rend.x<<"   "<<rend.y;
        title = t.str();
           SDL_WM_SetCaption(title.c_str(), 0);

        if(1000/FPS>SDL_GetTicks()-start)
               SDL_Delay(1000/FPS>SDL_GetTicks()-start);
    }
}
void Game::checkEvents()
{
     while(SDL_PollEvent(&this->event))
     {



        if(event.type == SDL_QUIT) isRunning = false;

            if(event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        right = true;
                    break;
                    case SDLK_LEFT:
                        left = true;
                    break;
                    case SDLK_UP:
                        up = true;
                    break;
                    case SDLK_DOWN:
                        down = true;
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
                        right = false;
                    break;
                    case SDLK_LEFT:
                        left = false;
                    break;
                    case SDLK_UP:
                        up = false;
                    break;
                    case SDLK_DOWN:
                        down = false;
                    break;
                    case SDLK_ESCAPE:
                        isRunning = false;
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
Game::~Game()
{

}




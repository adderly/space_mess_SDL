#include"Game.h"

Game::Game()
{

    isRunning = true;
    player = new Player();

}

void Game::MainLoop()
{
    while(isRunning)
    {
      //  start = SDL_GetTicks();

        checkEvents();
        rend.draw();
        std::cout<<SDL_GetError();

        SDL_GL_SwapBuffers();


			if(1000/FPS>SDL_GetTicks()-start)
               SDL_Delay(1000/FPS>SDL_GetTicks()-start);

         //  SDL_WM_SetCaption("ya", 0);

    }
}
void Game::checkEvents()
{
     while(SDL_PollEvent(&this->event))
     {

        if(event.type == SDL_QUIT) isRunning = false;
            if(SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                    rend.x++;
                    break;
                    case SDLK_LEFT:
                    rend.x--;
                    break;
                    case SDLK_ESCAPE:
                    isRunning = false;
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




#include"Game.h"

Game::Game()
{
    isRunning = true;
}
void Game::MainLoop()
{
    while(isRunning)
    {
      //  start = SDL_GetTicks();

        while(SDL_PollEvent(&event))
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
        rend.draw();
        std::cout<<SDL_GetError();

        SDL_GL_SwapBuffers();


			if(1000/FPS>SDL_GetTicks()-start)
               SDL_Delay(1000/FPS>SDL_GetTicks()-start);

         //  SDL_WM_SetCaption("ya", 0);

    }
}
Game::~Game()
{

}

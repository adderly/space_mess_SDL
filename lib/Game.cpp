#include"Game.h"

Game::Game():render()
{
    Running = true;
    Paused = false;
    Mainmenu = true;
}
void Game::movePlayers()
{
        if(right) x+=2;
        if(left)  x-=2;
        if(up) y-=2;
        if(down) y+=2;

//        if(right) player.x++;
//        if(left)  player.x--;
//        if(up) player.y++;
//        if(down) player.y--;
}

void Game::MainLoop()
{

    while(Running)
    {
      std::stringstream t;
      std::string title;

        movePlayers();
        checkEvents();

        draw();
        std::cout<<SDL_GetError();
        SDL_GL_SwapBuffers();



        t << event.motion.x<<"   "<<event.motion.y;
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
        if(event.type == SDL_QUIT) Running = false;

              if (event.type == SDL_MOUSEMOTION);
                    //fallowMouse(event.motion.x,event.motion.y);
              if(event.type == SDL_MOUSEBUTTONDOWN)
              {
                  switch(event.button.button)
                  {
                      case SDL_BUTTON_LEFT:
                      fallowMouse(event.motion.x,event.motion.y);
                      break;
                      case SDL_BUTTON_RIGHT:
                      break;
                      case SDL_BUTTON_MIDDLE:
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
                      break;
                      case SDL_BUTTON_RIGHT:
                      break;
                      case SDL_BUTTON_MIDDLE:
                      break;
                      case SDL_BUTTON_X1:
                      break;
                      case SDL_BUTTON_X2:
                      break;
                      default:
                      break;
                  }
              }


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




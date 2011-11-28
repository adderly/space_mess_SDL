#include<iostream>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_opengl.h>


void init()
{
  if(SDL_Init(SDL_INIT_VIDEO) < 0){}
  SDL_SetVideoMode(680,460,32,SDL_OPENGL);

  glMatrixMode();
  glClearColor(1,1,1,1);
  glShadeModel(GL_SMOOTH);
}

int main(int argc, char* argv[])
{
  init();

  bool isRunning = true;
  SDL_Event event;

  while(isRunning)
    {
        while(SDL_PollEvent(&event))
        {

        }
    }

  return 0;
}




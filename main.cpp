#include<iostream>
#include<sstream>
#include"lib/videoutil.h"
#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>

#pragma -lSDL -lGL -lGLU

using namespace std;
const int FPS = 30;
Uint32 start;

void init()
{

  glClearColor(1,0,0,1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45,width/height,1.0,500.0);
  glMatrixMode(GL_MODELVIEW);
  //glShadeModel(GL_SMOOTH);
}

void resize(SDL_Surface *surface = 0)
{

}
void draw()
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_TRIANGLES);
			glVertex3f(0.0,2.0,-5.0);
			glVertex3f(-2.0,-2.0,-5.0);
			glVertex3f(2.0,-2.0,-5.0);
		glEnd();
	}


int main(int argc, char* argv[])
{
    stringstream title;


    	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout<<"Sorry!";
		exit(1);
	}

  	if(SDL_SetVideoMode(width, height,bpp,SDL_SWSURFACE|SDL_OPENGL) < 0)
	{
		std::cout<<"hjh";
	}
  init();


  bool isRunning = true;
  SDL_Event event;

  while(isRunning)
    {
        start = SDL_GetTicks();
        title << 1000/FPS;
             while(SDL_PollEvent(&event))
			{
			  if(event.type == SDL_QUIT) isRunning = false;
			  else if(event.key.keysym.sym == SDLK_ESCAPE) isRunning = false;
			  if(event.key.keysym.sym == SDLK_RIGHT)
			  {
			      width += 30;
			     SDL_SetVideoMode(width,height,bpp,SDL_SWSURFACE|SDL_OPENGL);
			  }
			}

			draw();
			SDL_GL_SwapBuffers();


			if(1000/FPS>SDL_GetTicks()-start)
                SDL_Delay(1000/FPS>SDL_GetTicks()-start);

            SDL_WM_SetCaption(title.str().c_str(), 0);
            title.ignore(0);

    }

  return 0;
}







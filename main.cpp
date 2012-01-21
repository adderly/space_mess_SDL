#include<iostream>
#include<string>
#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>

#pragma -lSDL -lGL -lGLU


const int FPS = 30;
Uint32 start;

void init()
{

  glClearColor(1,0,0,1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45,680.0/460.0,1.0,500.0);
  glMatrixMode(GL_MODELVIEW);
  //glShadeModel(GL_SMOOTH);
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

void resize(int width, int height)
    {

    }

int main(int argc, char* argv[])
{
    	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout<<"Sorry!";
		exit(1);
	}

  	if(SDL_SetVideoMode(680, 460,32,SDL_SWSURFACE|SDL_OPENGL) < 0)
	{
		std::cout<<"hjh";
	}
  init();


  bool isRunning = true;
  SDL_Event event;

  while(isRunning)
    {
        start = SDL_GetTicks();

             while(SDL_PollEvent(&event))
			{
			  if(event.type == SDL_QUIT) isRunning = false;
			  else if(event.key.keysym.sym == SDLK_ESCAPE) isRunning = false;
			}

			draw();
			SDL_GL_SwapBuffers();

			if(1000/FPS>SDL_GetTicks()-start)
                SDL_Delay(1000/FPS>SDL_GetTicks()-start);

    }

  return 0;
}







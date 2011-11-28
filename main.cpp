#include<iostream>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_opengl.h>


void init()
{
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout<<"Sorry!";
		exit(1);
	}
  glClearColor(1,0,1,1);  
  SDL_SetVideoMode(680,460,32,SDL_OPENGL);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45,680.0/460.0,1.0,500.0);
  glMatrixMode(GL_MODELVIEW);
  glShadeModel(GL_SMOOTH);
}

void Draw()
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
  init(); 

  bool isRunning = true;
  SDL_Event event;
  
  while(isRunning)
    {
	      while(SDL_PollEvent(&event))
			{
			  if(event.type == SDL_QUIT) isRunning = false;
			  else if(event.key.keysym.sym = SDLK_ESCAPE) isRunning = false;
			}
			
			draw();
			SDL_GL_SwapBuffers();
    }

  return 0;
}




#include"render.h"

render::render()
{
    x = 1;
    prepare();

}
void render::prepare()
{
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) < 0)
    {
        std::cout<<"Could not init video" <<std::endl;
        exit(-1);
    }
    init();

    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

    screen = SDL_SetVideoMode(680,460,16,SDL_SWSURFACE|SDL_OPENGL);
}
void render::init()
{

    glClearColor(1,0,0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,680/460,1.0,500.0);
   // glMatrixMode(GL_MODELVIEW);
    glDisable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);

}


void render::reshape(int width, int height)
{

}
int render::setFullScreen()
{
    glLoadIdentity();
    SDL_SetVideoMode(680,460,32,SDL_FULLSCREEN|SDL_OPENGL|SDL_SWSURFACE);
}
void render::draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
			glVertex3f(0.0+this->x,2.0,-15.0);
			glVertex3f(-2.0+this->x,-2.0,-15.0);
			glVertex3f(2.0+this->x,-2.0,-14.0);
		glEnd();

}
render::~render(){}


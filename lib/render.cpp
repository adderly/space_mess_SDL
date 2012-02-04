#include"render.h"

render::render()
{
    x = 1;
    prepare();
    generator = new ParticleGenerator();
    generator->createParticles(1000);


}
void render::prepare()
{
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) < 0)
    {
        std::cout<<"Could not init video" <<std::endl;
        exit(-1);
    }


    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

    screen = SDL_SetVideoMode(width,height,bpp,SDL_SWSURFACE|SDL_OPENGL);
    init();
}
void render::init()
{

    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glViewport(0,0,width,height);
   // gluPerspective(45.0,680/460,1.0,500.0);
    //glMatrixMode(GL_MODELVIEW);
    glDisable(GL_DEPTH_TEST);
    glLoadIdentity();
    glShadeModel(GL_SMOOTH);
    glOrtho(0,width,height,0,-1,1);
    //SDL_WM_GrabInput(SDL_GRAB_ON);
}


void render::reshape(int width, int height)
{
    glClearColor(0,0,0,1);
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,width,height,0,-1,1);
}
int render::setFullScreen()
{
    glLoadIdentity();
    SDL_SetVideoMode(680,460,32,SDL_FULLSCREEN|SDL_OPENGL|SDL_SWSURFACE);
}
void render::draw()
{


    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,0);
        glBegin(GL_QUADS);
            glVertex2f(player.x+this->x,player.y+this->y);
            glVertex2f(player.x+player.width+this->x,player.y+this->y);
            glVertex2f(player.x+player.width+this->x,player.y+player.height+this->y);
            glVertex2f(player.x+this->x,player.y+player.height+this->y);
        glEnd();
		glBegin(GL_TRIANGLES);
			glVertex3f(0.0+this->x,2.0+this->y,-15.0);
			glVertex3f(-2.0+this->x,-2.0+this->y,-15.0);
			glVertex3f(2.0+this->x,-2.0+this->y,-15.0);
		glEnd();
		glBegin(GL_LINES);
            glVertex2f(0,0);
            glVertex2f(500,350);
		glEnd();

		glColor3f(1,0,0);
        glBegin(GL_QUADS);
                for(int n = 0; n < generator->particles.size();n++)
                {
                        glVertex2f(generator->particles[n]->pos_x,generator->particles[n]->pos_y);
                        glVertex2f(generator->particles[n]->pos_x+generator->particles[n]->width,generator->particles[n]->pos_y);
                        glVertex2f(generator->particles[n]->pos_x+generator->particles[n]->width,generator->particles[n]->pos_y+generator->particles[n]->height);
                        glVertex2f(generator->particles[n]->pos_x,generator->particles[n]->pos_y+generator->particles[n]->height);
                }
		glEnd();
		checkCollition();
        generator->evolveParticles();

}
void render::checkCollition()
{
    for(int f = 0;f < generator->particles.size();f++)
    {
        if(generator->particles[f]->pos_x < 0)
        {
            generator->particles[f]->speed_x = - generator->particles[f]->speed_x;
            if(generator->particles[f]->speed_x > generator->particles[f]->speed_y) generator->particles[f]->speed_y *= 1.2;
        }
        if(generator->particles[f]->pos_y < 0)
        {
            generator->particles[f]->speed_y = - generator->particles[f]->speed_y;
            if(generator->particles[f]->speed_y > generator->particles[f]->speed_x) generator->particles[f]->speed_x *=0.1;
        }
        if(generator->particles[f]->pos_x+generator->particles[f]->width > width)
        {
            generator->particles[f]->speed_x = - generator->particles[f]->speed_x;
        }
        if(generator->particles[f]->pos_y+generator->particles[f]->height > height)
        {
            generator->particles[f]->speed_y = - generator->particles[f]->speed_y;
        }
    }
}
void render::drawMainMenu(){}
void render::drawPauseMenu(){}
void render::releaseResources(){}
void render::fallowMouse(int mouse_x,int mouse_y)
{
    for(int n = 0;n< generator->particles.size();n++)
    {
        if(generator->particles[n]->pos_x > x || generator->particles[n]->pos_x < x)
        {
           generator->particles[n]->speed_x = - generator->particles[n]->speed_x;
           generator->particles[n]->x_max = mouse_x;
        }
         if(generator->particles[n]->pos_y > y || generator->particles[n]->pos_y < y)
        {
           generator->particles[n]->speed_y = - generator->particles[n]->speed_y;
           generator->particles[n]->y_max = mouse_y;
        }

    }
}
render::~render(){}


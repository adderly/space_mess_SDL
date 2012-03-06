#include"Render.h"

Render::Render():Environment()
{
    camera.h  = 660;
    camera.w = 460;
    camera.x = 0;
    camera.y = 0;
    x = 1;
    loadSettings();
    prepare();
    generator = new ParticleGenerator();
    generator->createParticles(500);
    player = new Player(generator);
    texture = loadTexture("resources/images/brick.bmp");
    music = new Audio();
}
void Render::shut()
{
    float color[] = {255,222,225};
    Particle* p = new Particle(player->x+player->width,-1*player->y+(player->width/2),0,2,gravity,0,10,color);
    p->setSize(20,20);
    generator->addParticle(p);
}
void Render::prepare()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout<<"Could not init video" <<std::endl;
        saveLog("Could Not INIT VIDEO");
        exit(-1);
    }

    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

    screen = SDL_SetVideoMode(width,height,bpp,SDL_HWSURFACE|SDL_OPENGLBLIT);
    background = IMG_Load("resources/images/brick.bmp");
    if( background == NULL) {
        std::cout<<"Unable to load back.bmp" <<std::endl;
        saveLog("Could Not load resource/images/back.bmp");
        exit(-1);
    }
    background = SDL_DisplayFormat(background);
    init();
}
void Render::init()
{
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glViewport(0,0,width,height);
    //gluPerspective(45.0,680/460,1.0,500.0);
    glMatrixMode(GL_MODELVIEW);
    //glDisable(GL_DEPTH_TEST);
    glLoadIdentity();
    glShadeModel(GL_SMOOTH);
    glOrtho(0,width,height,0,-1,1);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_ALPHA);
    //SDL_WM_GrabInput(SDL_GRAB_ON);
}
void Render::reshape(int width, int height)
{
    glClearColor(0,0,0,1);
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,width,height,0,-1,1);
}
int Render::setFullScreen()
{
    glLoadIdentity();
    SDL_SetVideoMode(680,460,32,SDL_FULLSCREEN|SDL_OPENGL|SDL_HWSURFACE);
}
void Render::draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
   // glColor3f(0,1,0);

   /***************BLITExample********************
   *    UpdateRect IS The KEY HERE!
   *
   */
   SDL_BlitSurface(background,NULL,screen,NULL);
   SDL_UpdateRect(screen, 0, 0, background->w, background->h);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture);
        glBegin(GL_QUADS);
            glVertex2f(player->x+this->x,player->y+this->y); glTexCoord2f(0.0,1.0);
            glVertex2f(player->x+player->width+this->x,player->y+this->y);  glTexCoord2f(1.0,1.0);
            glVertex2f(player->x+player->width+this->x,player->y+player->height+this->y);   glTexCoord2f(0.0,1.0);
            glVertex2f(player->x+this->x,player->y+player->height+this->y); glTexCoord2f(0.0,0.0);
        glEnd();
       // glDisable(GL_TEXTURE_2D);


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
        //SDL_BlitSurface(screen,&camera,background,NULL);


        SDL_GL_SwapBuffers();
}
void Render::checkCollition()
{
    for(int f = 0;f < generator->particles.size();f++)
    {
        if( generator->particles[f]->alive == true)
        {
            if(generator->particles[f]->pos_x < 2)
            {
                generator->particles[f]->speed_x = -1 * generator->particles[f]->speed_x;
                if(generator->particles[f]->speed_x > generator->particles[f]->speed_y) generator->particles[f]->speed_y *= 1.01;
                //generator->particles[f]->alive = false;
            }
            if(generator->particles[f]->pos_y < 2)
            {
                generator->particles[f]->speed_y = -1 * generator->particles[f]->speed_y;
                if(generator->particles[f]->speed_y > generator->particles[f]->speed_x) generator->particles[f]->speed_x *=1.01;
                // generator->particles[f]->alive = false;
            }
            if(generator->particles[f]->pos_x+generator->particles[f]->width >= width)
            {
                generator->particles[f]->speed_x = - generator->particles[f]->speed_x;
               if(generator->particles[f]-> width > 10) generator->createParticles(60);
                // generator->particles[f]->alive = false;
            }
            if(generator->particles[f]->pos_y+generator->particles[f]->height >= height-5)
            {
                generator->particles[f]->speed_y = - generator->particles[f]->speed_y;
                // generator->particles[f]->alive = false;
            }
        }else
        {
           // delete generator->particles[f];
        }
    }
}
void Render::drawMainMenu(){}
void Render::drawPauseMenu()
{
}
void Render::releaseResources()
{
}
void Render::fallowMouse(int mouse_x,int mouse_y)
{
    for(int n = 0;n< generator->particles.size();n++)
    {

    }
}
void Render::clean(){}
Render::~Render(){}


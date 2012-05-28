#include"Render.h"

namespace Graphics
{

Render::Render():RenderArea(),Drawer()
{

    camera.h  = 660;
    camera.w = 460;
    camera.x = 0;
    camera.y = 0;
    x = 1;
    prepare();

    generator = new ParticleGenerator();
    generator->createParticles(500);
    player = new Player(generator);
    texture = loadTexture("resources/images/brick.bmp");

    music = new Audio();
    /*  MENU */
    menuH = new MenuHandler();
    // menu->setVisible(false);
    //menu->setBackground(SDL_DisplayFormat(IMG_Load("resources/images/brick.bmp")));
}
void Render::prepare()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout<<"Could not init video" <<std::endl;
        saveLog("Could Not INIT VIDEO");
        exit(-1);
    }

    putenv("SDL_VIDEO_WINDOW_POS=center");
    //putenv("SDL_VIDEO_CENTERED=1");

    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

    screen = SDL_SetVideoMode(width,height,bpp,SDL_HWSURFACE|SDL_OPENGLBLIT);
    background = SDL_DisplayFormatAlpha(IMG_Load("resources/images/back.bmp"));
    if( background == NULL)
    {
        std::cout<<"Unable to load back.bmp" <<std::endl;
        saveLog("Could Not load resource/images/back.bmp");
        exit(-1);
    }

    bt = loadTexture("resources/images/back.bmp");
    // SDL_SetColorKey(background,SDL_SRCCOLORKEY,SDL_MapRGB(background->format,0x00,0xff,0xff));

    init();
}
void Render::init()
{
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glViewport(0,0,width,height);
    //gluPerspective(45.0,680/460,1.0,500.0);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glDisable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glOrtho(0,width,height,0,-1,1);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_ALPHA);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
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


    for(d_tator = drawables.begin(); d_tator != drawables.end(); d_tator++)
    {

// TODO (moisex#1#): Enhance the Drawing, evaluating the states of the drawables, in this case when selected,clicked.\

        if((**d_tator).getIsDefaulColor())
        {
                       glColor4f((**d_tator).color[0],(**d_tator).color[1], (**d_tator).color[2],(**d_tator).color[3]);
        }
        else glColor4f(1.0,0.0,0.0,0.0);

        /*Draws Dipending on the type of object*/

        if((**d_tator).isQuad)
        {
            glBegin(GL_QUADS);
            glVertex3f((**d_tator).x ,(**d_tator).y,(**d_tator).z);
            glVertex3f((**d_tator).x + (**d_tator).width,(**d_tator).y,(**d_tator).z);
            glVertex3f((**d_tator).x+ (**d_tator).width,(**d_tator).y+ (**d_tator).height,(**d_tator).z);
            glVertex3f((**d_tator).x,(**d_tator).y+ (**d_tator).height,(**d_tator).z);
            glEnd();
        }
        else
        {
            glBegin(GL_TRIANGLES);
            glVertex3f((**d_tator).x,(**d_tator).y,(**d_tator).z);
            glVertex3f((**d_tator).x + (**d_tator).width,(**d_tator).y,(**d_tator).z);
            glVertex3f((**d_tator).x+ (**d_tator).width,(**d_tator).y+ (**d_tator).height,(**d_tator).z);
            glVertex3f((**d_tator).x,(**d_tator).y+ (**d_tator).height,(**d_tator).z);
            glEnd();
        }
        /***************BLITExample********************
        *    UpdateRect IS The KEY HERE!
        *
        */

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,bt);
        glBegin(GL_QUADS);
        glVertex2f(player->x+this->x,player->y+this->y);
        glTexCoord2f(0.0,0.0);
        glVertex2f(player->x+player->width+this->x,player->y+this->y);
        glTexCoord2f(1.0,0.0);
        glVertex2f(player->x+player->width+this->x,player->y+player->height+this->y);
        glTexCoord2f(1.0,1.0);
        glVertex2f(player->x+this->x,player->y+player->height+this->y);
        glTexCoord2f(0.0,1.0);
        glEnd();

        glDisable(GL_TEXTURE_2D);

        glBegin(GL_QUADS);
        glColor4f(1.0,0.0,0.0,0.5);
        glVertex2f(10,10);
        glVertex2f(100,10);
        glVertex2f(100,100);
        glVertex2f(10,100);
        glEnd();
        glColor4f(1.0,0.0,0.0,0.5);
        glBegin(GL_QUADS);
        for(int n = 0; n < generator->particles.size(); n++)
        {
            glVertex2f(generator->particles[n]->pos_x,generator->particles[n]->pos_y);
            glVertex2f(generator->particles[n]->pos_x+generator->particles[n]->width,generator->particles[n]->pos_y);
            glVertex2f(generator->particles[n]->pos_x+generator->particles[n]->width,generator->particles[n]->pos_y+generator->particles[n]->height);
            glVertex2f(generator->particles[n]->pos_x,generator->particles[n]->pos_y+generator->particles[n]->height);
        }
        glEnd();


        //generator->evolveParticles();
        // if(menu->visible)drawMainMenu();


    }
}
    Render::~Render()
    {}

}

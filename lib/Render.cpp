#include"Render.h"

namespace Graphics
{

Render::Render():Drawer(),RenderArea()
{

    camera.h  = 660;
    camera.w = 460;
    camera.x = 0;
    camera.y = 0;
    x = 1;
 //  prepare();
//
//    generator = new ParticleGenerator();
//    generator->createParticles(500);
//    player = new Player(generator);
//    texture = loadTexture("resources/images/brick.bmp");
//
//    music = new Audio();
//    /*  MENU */
//    menuH = new MenuHandler();
//    // menu->setVisible(false);
//    //menu->setBackground(SDL_DisplayFormat(IMG_Load("resources/images/brick.bmp")));
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

    screen = SDL_SetVideoMode(getScreenWidth(),getScreenHeight(),bpp,SDL_HWSURFACE|SDL_OPENGLBLIT);
//    background = SDL_DisplayFormatAlpha(IMG_Load("resources/images/back.bmp"));
//    if( background == NULL)
//    {
//        std::cout<<"Unable to load back.bmp" <<std::endl;
//        saveLog("Could Not load resource/images/back.bmp");
//        exit(-1);
//    }
//
//    bt = loadTexture("resources/images/back.bmp");
    // SDL_SetColorKey(background,SDL_SRCCOLORKEY,SDL_MapRGB(background->format,0x00,0xff,0xff));

    init();

//    generator = new ParticleGenerator();
//    generator->createParticles(500);
//    player = new Player(generator);
//    texture = loadTexture("resources/images/brick.bmp");
//
//    music = new Audio();
//    /*  MENU */
//    menuH = new MenuHandler();
    // menu->setVisible(false);
    //menu->setBackground(SDL_DisplayFormat(IMG_Load("resources/images/brick.bmp")));
}
void Render::init()
{
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glViewport(0,0,getScreenWidth(),getScreenHeight());
    //gluPerspective(45.0,680/460,1.0,500.0);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glDisable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glOrtho(0,getScreenWidth(),getScreenHeight(),0,-1,1);
   // glEnable(GL_TEXTURE_2D);
  //  glEnable(GL_ALPHA);
   // glEnable(GL_BLEND);
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
        glColor3f(0,1,0);


    for(d_tator = drawables.begin(); d_tator != drawables.end(); d_tator++)
    {

// TODO (moisex#1#): Enhance the Drawing, evaluating the states of the drawables, in this case when selected,clicked.\

           (**d_tator).draw();
//        if((**d_tator).mouseover )
//                glColor4f((**d_tator).selectedColor[0],(**d_tator).selectedColor[1], (**d_tator).selectedColor[2],(**d_tator).selectedColor[3]);
//        else glColor4f((**d_tator).color[0],(**d_tator).color[1], (**d_tator).color[2],(**d_tator).color[3]);
//
//
//        /*Draws Dipending on the type of object*/
//
//        if((**d_tator).isQuad)
//        {
//            glBegin(GL_QUADS);
//            glVertex3f((**d_tator).x ,(**d_tator).y,(**d_tator).z);
//            glVertex3f((**d_tator).x + (**d_tator).width,(**d_tator).y,(**d_tator).z);
//            glVertex3f((**d_tator).x+ (**d_tator).width,(**d_tator).y+ (**d_tator).height,(**d_tator).z);
//            glVertex3f((**d_tator).x,(**d_tator).y+ (**d_tator).height,(**d_tator).z);
//            glEnd();
//        }
//        else
//        {
//            glBegin(GL_TRIANGLES);
//            glVertex3f((**d_tator).x,(**d_tator).y,(**d_tator).z);
//            glVertex3f((**d_tator).x + (**d_tator).width,(**d_tator).y,(**d_tator).z);
//            glVertex3f((**d_tator).x+ (**d_tator).width,(**d_tator).y+ (**d_tator).height,(**d_tator).z);
//            glVertex3f((**d_tator).x,(**d_tator).y+ (**d_tator).height,(**d_tator).z);
//            glEnd();
//        }
    }
//        /***************BLITExample********************
//        *    UpdateRect IS The KEY HERE!
//        *
//        */
//
//        glEnable(GL_TEXTURE_2D);
//        glBindTexture(GL_TEXTURE_2D,bt);
//        glBegin(GL_QUADS);
//        glVertex2f(player->x+this->x,player->y+this->y);
//        glTexCoord2f(0.0,0.0);
//        glVertex2f(player->x+player->width+this->x,player->y+this->y);
//        glTexCoord2f(1.0,0.0);
//        glVertex2f(player->x+player->width+this->x,player->y+player->height+this->y);
//        glTexCoord2f(1.0,1.0);
//        glVertex2f(player->x+this->x,player->y+player->height+this->y);
//        glTexCoord2f(0.0,1.0);
//        glEnd();
//
//        glDisable(GL_TEXTURE_2D);

//        glColor4f(1.0,0.0,0.0,0.5);
//        glBegin(GL_QUADS);
//        for(int n = 0; n < generator->particles.size(); n++)
//        {
//            glVertex2f(generator->particles[n]->pos_x,generator->particles[n]->pos_y);
//            glVertex2f(generator->particles[n]->pos_x+generator->particles[n]->width,generator->particles[n]->pos_y);
//            glVertex2f(generator->particles[n]->pos_x+generator->particles[n]->width,generator->particles[n]->pos_y+generator->particles[n]->height);
//            glVertex2f(generator->particles[n]->pos_x,generator->particles[n]->pos_y+generator->particles[n]->height);
//        }
//        glEnd();
//

        //generator->evolveParticles();
        // if(menu->visible)drawMainMenu();


  //  }
}
void Render::drawContainer(Drawable* container)
{
            if(container->SELECTED)  glColor4f(1,container->selectedColor[1],container->selectedColor[2],container->selectedColor[3]);
            else if( container->MOUSE_OVER)  glColor4f(container->selectedColor[0],container->selectedColor[1],container->selectedColor[2],container->selectedColor[3]);
            else glColor4f(container->color[0],container->color[1],container->color[2],container->color[3]);

            if(container->isQuad)
            {
                    glBegin(GL_QUADS);
                    glVertex3f(container->x,container->y,container->z);
                    glVertex3f(container->x+container->width,container->y,container->z);
                    glVertex3f(container->x+container->width,container->y+container->height,container->z);
                    glVertex3f(container->x,container->y+container->height,container->z);
                    glEnd();
            }
            else
            {
                    glBegin(GL_TRIANGLES);
                    glVertex3f(container->x+(container->width/2),container->y,container->z);
                    glVertex3f(container->x+container->width,container->y+container->height,container->z);
                    glVertex3f(container->x,container->y+container->height,container->z);
                    glEnd();
            }

            saveLog("before casting...");
             Container *tmp = dynamic_cast<Container*> (container);

            for(int n = 0;n < tmp->items.size();n++)
            {
                 if(tmp->items[n]->SELECTED)  glColor4f(1,tmp->items[n]->selectedColor[1],tmp->items[n]->selectedColor[2],tmp->items[n]->selectedColor[3]);
                else if( tmp->items[n]->MOUSE_OVER)  glColor4f(tmp->items[n]->selectedColor[0],tmp->items[n]->selectedColor[1],tmp->items[n]->selectedColor[2],tmp->items[n]->selectedColor[3]);
                else    glColor4f(tmp->items[n]->color[0],tmp->items[n]->color[1],tmp->items[n]->color[2],tmp->items[n]->color[3]);

                if(tmp->items[n]->isQuad)
                {
                        glBegin(GL_QUADS);
                        glVertex3f(tmp->items[n]->x,tmp->items[n]->y,tmp->items[n]->z);
                        glVertex3f(tmp->items[n]->x+tmp->items[n]->width,tmp->items[n]->y,tmp->items[n]->z);
                        glVertex3f(tmp->items[n]->x+tmp->items[n]->width,tmp->items[n]->y+tmp->items[n]->height,tmp->items[n]->z);
                        glVertex3f(tmp->items[n]->x,tmp->items[n]->y+tmp->items[n]->height,tmp->items[n]->z);
                        glEnd();
                }
                else
                {
                        glBegin(GL_TRIANGLES);
                        glVertex3f(tmp->items[n]->x+(tmp->items[n]->width/2),tmp->items[n]->y,tmp->items[n]->z);
                        glVertex3f(tmp->items[n]->x+tmp->items[n]->width,tmp->items[n]->y+tmp->items[n]->height,tmp->items[n]->z);
                        glVertex3f(tmp->items[n]->x,tmp->items[n]->y+tmp->items[n]->height,tmp->items[n]->z);
                        glEnd();
                }
// TODO (moisex#1#): Draw Container Items, is segmenting...               if(tmp->items[n]->isContainer)   Render::drawContainer(tmp->items[n]);

            }

}
void Render::addDrawable(Drawable* element)
{
    drawables.push_back(element);
}

Render::~Render()
{

}

}

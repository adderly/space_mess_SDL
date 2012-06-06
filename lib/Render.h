

/*New*/
#include"RenderArea.h"
#include"Drawer.h"
#include"Container.h"
/*****/
#include"TextRender.h"
#include<SDL/SDL.h>
#include<SDL/SDL_opengl.h>
#include<SDL/SDL_thread.h>
#include<GL/glu.h>
#include<iostream>
#include"keys.h"
#include"videoutil.h"
#include"ParticleGenerator.h"
#include"Player.h"
#include"Environment.h"
#include"TextureLoader.h"
#include"Audio/AudioPlayback.h"
#include"Log.h"
#include"MenuHandler.h"

namespace Graphics{
#ifndef RENDER
#define RENDER

    using namespace AudioPlayback;

    class Render: public RenderArea, public Drawer
    {

        /*New Stuff*/
    // TODO (moisex#1#): Change the vector for a binary tree, the drawing will be done from the lower Z axis to the nearest.\
    Each node in the binary tree will be capable of having its own childs.
        /***********/

           SDL_Surface *screen,*background;
           SDL_Rect camera;
           const SDL_VideoInfo *info;
           ParticleGenerator* generator;
           unsigned int texture,bt;
        public:
            std::vector<Drawable*> drawables;
            std::vector<Drawable*>::iterator d_tator;//Drawble Iterator
          Audio* music;
          //Menu* menu;
          Actors::Player* player;
          MenuHandler* menuH;
          int x,y;
          Render();
          ~Render();
          void prepare();
          void init();
          void reshape(int width,int height);
          static int setFullScreen();
          void addDrawable(Drawable*);
          void draw();
          static void drawContainer(Drawable*);
          SDL_Surface* getScreen(){return this->screen;}
    };
#endif
}

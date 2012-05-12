
#include"../utils/TextRender.h"
#include<SDL/SDL.h>
#include<SDL/SDL_opengl.h>
#include<SDL/SDL_thread.h>
#include<GL/glu.h>
#include<iostream>
#include"../utils/keys.h"
#include"videoutil.h"
#include"ParticleGenerator.h"
#include"Player.h"
#include"Environment.h"
#include"../utils/TextureLoader.h"
#include"Audio/AudioPlayback.h"
#include"../utils/Log.h"
#include"MenuHandler.h"

namespace Graphics{
#ifndef RENDER
#define RENDER

using namespace AudioPlayback;

class Render:public Environment
{

       SDL_Surface *screen,*background;
       SDL_Rect camera;
       const SDL_VideoInfo *info;
       ParticleGenerator* generator;
       unsigned int texture,bt;



  public:
      Audio* music;
      //Menu* menu;
      Player* player;
      MenuHandler* menuH;
      int x,y;
      Render();
      ~Render();
      void prepare();
      void init();
      void reshape(int width,int height);
      static int setFullScreen();
      void checkCollition();
      void draw();
      void drawMainMenu();
      void drawPauseMenu();
      void releaseResources();
      void fallowMouse(int x,int y);
      void shut();
      void clean();
      SDL_Surface* getScreen(){return this->screen;}
};
#endif
}

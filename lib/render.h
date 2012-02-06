#include"../utils/keys.h"
#include"videoutil.h"
#include"ParticleGenerator.h"
#include"Player.h"
#include"Environment.h"
#include"../utils/TextRender.h"
#include<SDL/SDL.h>
#include<SDL/SDL_opengl.h>
#include<SDL/SDL_thread.h>
#include<GL/glu.h>
#include<iostream>
#include"../utils/TextureLoader.h"
#include"AudioPlayback.h"


class render
{
   SDL_Surface *screen;
   const SDL_VideoInfo *info;
   ParticleGenerator* generator;
   unsigned int texture;
   Text* text;
    Audio* music;
    friend class Game;

 public:
  Player player;
  int x;
  int y;
  render();
  ~render();
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
};

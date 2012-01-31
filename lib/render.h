#include"../utils/keys.h"
#include"Player.h"
#include"Environment.h"
#include<SDL/SDL.h>
#include<SDL/SDL_opengl.h>
#include<SDL/SDL_thread.h>
#include<GL/glu.h>
#include<iostream>



class render
{
   SDL_Surface *screen;
   const SDL_VideoInfo *info;


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
  void draw();
};

#include"../utils/Window.h"
#include"Environment.h"
#include<SDL/SDL.h>
#include<SDL/SDL_opengl.h>
#include<GL/glu.h>
#include<iostream>
#include<sstream>


class render
{
   SDL_Surface *screen;
     const SDL_VideoInfo *info;

 public:
  int x;
  render();
  void prepare();
  void init();
  void reshape(int width,int height);
  static int setFullScreen();
  void draw();
};

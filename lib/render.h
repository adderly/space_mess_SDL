#include"..\utils\Window.h"


class render:Window
{
    unsigned int screen;

 public:
  render();
  int init();
  void reshape(int width,int height);
  static int setFullScreen();
  void draw();
};

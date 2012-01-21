
class render
{
    SDL_Surface screen;

 public:
  render();
  int init();
  void reshape(int width,int height);
  static int setFullScreen();
  void draw();
};

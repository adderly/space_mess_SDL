#include"Render.h"

#include<sstream>

using namespace Graphics;

class Game:public Render
{

    int* mouseX,*mouseY;
    static const int FPS = 20;
    Uint32 start;
    //SDL_Event event; it is in Keys now Static ;)/
    friend class Render;
public:
    Game();
    void movePlayers();
    void MainLoop();
    void checkEvent();
    void setTitle(int w,int h);
    ~Game();

};



#include"Render.h"
#include<sstream>



class Game:public Render
{
    Render* rend;
    bool Running,Paused,Mainmenu,GRABBED;
    int* mouseX,*mouseY;
    static const int FPS = 20;
    Uint32 start;
    SDL_Event event;
    friend class Render;

    public:
    Game();
    void movePlayers();
    void MainLoop();
    void checkEvents();
    void setTitle(int w,int h);
    ~Game();

};

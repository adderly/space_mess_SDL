#include"Render.h"
#include<sstream>


class Game:public Render
{

    bool Running,Paused,Mainmenu,GRABBED;
    int* mouseX,*mouseY;
    static const int FPS = 30;
    Uint32 start;
    //SDL_Event event; it is in Keys now Static ;)/
    friend class Render;

    public:
    Game();
    void movePlayers();
    void MainLoop();
    void checkEvents();
    void setTitle(int w,int h);
    ~Game();

};

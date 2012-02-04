#include"render.h"
#include<sstream>



class Game:render
{

    render rend;
    bool Running,Paused,Mainmenu;
    int* mouseX,*mouseY;
    static const int FPS = 30;
    Uint32 start;
    SDL_Event event;
    SDL_Thread* ethread ;
    void (Game::*fn)(void *);
    friend class render;


    public:
    Game();
    void movePlayers();
    void MainLoop();
    void checkEvents();
    void setTitle(int w,int h);
    ~Game();

};

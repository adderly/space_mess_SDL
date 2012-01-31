#include"render.h"
#include<sstream>



class Game:render
{

    render rend;
    bool isRunning;
    static const int FPS = 30;
    Uint32 start;

    SDL_Event event;
    SDL_Thread* ethread ;
    void (Game::*fn)(void *);


    public:
    Game();
    void movePlayers();
    void MainLoop();
    void checkEvents();
    ~Game();

};

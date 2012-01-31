
//#include"videoutil.h"

#include"render.h"
#include"Player.h"

class Game:render
{

    render rend;
    bool isRunning;
    static const int FPS = 30;
    Uint32 start;
    Player* player;
    SDL_Event event;
    void (Game::*fn)(void *);


    public:
    Game();
    void MainLoop();
    void checkEvents();
    ~Game();

};

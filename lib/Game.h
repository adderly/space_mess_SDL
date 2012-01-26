
//#include"videoutil.h"

#include"render.h"

class Game:render
{

    render rend;
    bool isRunning;
    static const int FPS = 30;
    Uint32 start;

    SDL_Event event;

    public:
    Game();
    void MainLoop();
    ~Game();

};

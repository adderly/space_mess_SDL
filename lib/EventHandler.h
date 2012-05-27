#include"../utils/keys.h"


class EventHandler
{
    SDL_Event *event;
public:
    EventHandler(SDL_Event *event);
    void check();
    ~EventHandler();

};




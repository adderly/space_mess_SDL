

#ifndef TRIGGERER
#define TRIGGERER

class EventTriggerer
{
    SDL_Event event;
    public:
    EventTriggerer();
    EventTriggerer(SDL_Event);
    ~EventTriggerer();
    void check();
    void check(SDL_Event);
    void trigger();
};

#endif


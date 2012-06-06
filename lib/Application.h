#include"Core.h"
#include"keys.h"


#ifndef APPLICATION
#define APPLICATION
using namespace Graphics;

class Application : public EventTriggerer
{
    friend class Core;
    Core *core;

    public:
    void setUp();
    void cleanUp();
    void draw();
    void loadPreviousConf();
    int execute();
    inline void check();
    void trigger();
    inline void check(SDL_Event&);
    void checkDrawable(Drawable*);
    inline void checkMouseDown(SDL_Event&);
    inline void checkMouseUp(SDL_Event&);
    inline void checkKeyUp(SDL_Event&);
    inline void checkKeyDown(SDL_Event&);
    Application();
    ~Application();
};

#endif

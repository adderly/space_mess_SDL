#include"Render.h"
#include"EventTriggerer.h"
#include"keys.h"
#include"Container.h"

#ifndef CORE
#define CORE

/*
    Theorically this would control interactions Drawing,
    and handle the flow
*/
using namespace Graphics;

class Core: public Graphics::Render
{
// TODO (moisex#1#): Link The Event,Drawing with the core.

public://drawing,events

    Core();
    ~Core();

    int run();
    void test();

};

#endif




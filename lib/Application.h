
#include"Core.h"


#ifndef APPLICATION
#define APPLICATION

class Application : public Core
{

    public:
    void setUp();
    void loadPreviousConf();
    int execute();
    Application();
    ~Application();


};

#endif

#include"../lib/Render.h"
#include<map>


using namespace Graphics;
class Editor:public Render
{
private:
    friend class Render;
    Menu* mainmenu;
    //ObjectFactory factory;
    //map<objects>
    //world
    //eventHandler
    //writer(file)
    //reader(file)

public:
    Editor();
    void loop();
    void closes();
    void check();
    void init();
    ~Editor();



};



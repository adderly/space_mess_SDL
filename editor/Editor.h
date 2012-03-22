#include"../lib/Render.h"

#include<map>


class Editor:public Render
{
    private:
    friend class Render;
        Menu* mainmenu;
        //ObjectFactory factory;
        //map<objects>
        //world
        //list of menus
        //eventHandler
        //writer(file)
        //reader(file)

    public:
        Editor();
        void loop();
        void check();
        void init();
        ~Editor();



};



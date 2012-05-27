#include"Editor.h"


Editor::Editor():Render()
{
    init();

}
void Editor::closes()
{
    saveLog("from signal");
}
void Editor::loop()
{


    while(Running)
    {
        check();
        draw();
        menuH->current->draw();
        SDL_GL_SwapBuffers();
        //draw();
    }
}
void Editor::check()
{
    while(SDL_PollEvent(&event))
    {
        if(event.type== SDL_QUIT) Running = false;
        menuH->check(&event);

        //switch(event.key.keysyn.sym){}
    }
}
void Editor::init()
{

    GridOptions grid;
    grid.spacing = 10;
    grid.columns = 3;


    mainmenu =  new Menu(width,height,450,350);
    mainmenu->detected.connect(sigc::mem_fun(this, &Editor::closes));
    mainmenu->setBackground(getScreen());
    mainmenu->setGrid(grid);
    mainmenu->setColor(0.0,0.5,0.5,0.5);
    mainmenu->setVisible(true);
    menuH->setMainMenu(mainmenu);
    mainmenu->detected.emit();
    float posx = mainmenu->x+mainmenu->width;
    float posy = mainmenu->y+mainmenu->height;
    MenuOption* op_exit = new MenuOption(posx-120,posy-60,120,60);
    op_exit->text = "exit";
    op_exit->enable = true;
    op_exit->setVoidCallBack(exit);
    mainmenu->addOption(op_exit);

}
Editor::~Editor() {}

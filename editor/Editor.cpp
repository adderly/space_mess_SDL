#include"Editor.h"


Editor::Editor():Render()
{
    GridOptions grid;
    grid.spacing = 50;
    grid.columns = 2;
    mainmenu =  new Menu(width,height,450,350);
    mainmenu->setBackground(getScreen());
    //mainmenu->setGrid(grid);


}
void Editor::loop()
{
    while(Running)
    {
        mainmenu->check(event);
        mainmenu->draw();
        SDL_GL_SwapBuffers();
        //draw();
    }
}
void Editor::init()
{

}
Editor::~Editor(){}

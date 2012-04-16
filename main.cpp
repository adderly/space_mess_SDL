#include"lib/Game.h"
//#include"editor/Editor.h"

#pragma -lSDL -lGL -lGLU

using namespace std;

int main(int argc, char* argv[])
{
//    Editor* editor = new Editor();
//    editor->loop();
//
    Game *game = new Game();
    game->MainLoop();

//    DisplayConfig* config =  new DisplayConfig();
//    config->readConfig();
//    config->writeConfig();

  return 0;
}







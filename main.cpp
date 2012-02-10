#include"lib/Game.h"
//#include"lib/DisplayConfig.h"

#pragma -lSDL -lGL -lGLU

using namespace std;

int main(int argc, char* argv[])
{

    Game *game = new Game();
    game->MainLoop();
//    DisplayConfig* config =  new DisplayConfig();
//    config->readConfig();
//    config->writeConfig();

  return 0;
}







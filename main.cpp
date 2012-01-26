#include"lib/Game.h"

#pragma -lSDL -lGL -lGLU

using namespace std;

int main(int argc, char* argv[])
{

    Game *game = new Game();
    game->MainLoop();


  return 0;
}







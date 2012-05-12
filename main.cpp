//#include"lib/Game.h"
#include"editor/Editor.h"
#include "utils/sigc++/sigc++.h"

#pragma -lSDL -lGL -lGLU

using namespace std;

class AlienDetector
{
public:
    AlienDetector();

    void run();

    sigc::signal<void> signal_detected;
};

AlienDetector::AlienDetector(){}
void AlienDetector::run(){}


void warn_people()
{
    cout << "There are aliens in the carpark!" << endl;
}


int main(int argc, char* argv[])
{

    // AlienDetector mydetector;
    // mydetector.signal_detected.connect( sigc::ptr_fun(warn_people) );
    // mydetector.run();
     Editor* editor = new Editor();
     editor->loop();

//    Game *game = new Game();
//    game->MainLoop();

//    DisplayConfig* config =  new DisplayConfig();
//    config->readConfig();
//    config->writeConfig();

  return 0;
}







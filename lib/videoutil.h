#include"DisplayConfig.h"


static unsigned int fullscreen = 0;
static unsigned int width = 680;
static unsigned int height = 460;
static unsigned int bpp = 32;
static unsigned int sound = 0;


static void loadSettings()
{
    map<std::string,int> set;
    DisplayConfig* config = new DisplayConfig();
    config->readConfig();
    set = config->getsettings();
    fullscreen = set.find("fullscreen")->second;
    width = set.find("width")->second;
    height = set.find("height")->second;
}







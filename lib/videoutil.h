#include"DisplayConfig.h"

#ifndef VUTIL
#define VUTIL

static unsigned int settings_fullscreen = 0;
static unsigned int settings_width = 680;
static unsigned int settings_height = 460;
static unsigned int bpp = 32;
static unsigned int sound = 0;


static void loadSettings()
{
    map<std::string,int> set;
    DisplayConfig* config = new DisplayConfig();
    config->readConfig();
    set = config->getsettings();
    settings_fullscreen = set.find("fullscreen")->second;
    settings_width = set.find("width")->second;
    settings_height = set.find("height")->second;
}



#endif




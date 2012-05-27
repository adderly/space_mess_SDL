#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<stdlib.h>
#include<cstdlib>
#include"../utils/Log.h"

//This Will Read The Configurations From A Formated Text
//File
//Display Configuration Manager
//Settings FileName = xconfig.dat

using namespace std;
#ifndef DISPLAYCONFIG
#define DISPLAYCONFIG
class DisplayConfig
{
    string defaults;
    ifstream input;
    ofstream output;
    string tosave;
    map<string, int> settings;
    map<string, int>::iterator it;

public:
    DisplayConfig();
    map<string, int> &getsettings();
    void addToMap(const string ,const int);
    bool readConfig();
    int writeConfig();
    ~DisplayConfig();
};
#endif

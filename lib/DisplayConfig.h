#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cstdlib>

//This Will Read The Configurations From A Formated Text
//File
//Display Configuration Manager
//Settings FileName = xconfig.dat

using namespace std;

class DisplayConfig
{
    ifstream input;
    ofstream output;
    string tosave;
    map<char,string> settings;

    public:
    string defaults;
    DisplayConfig();
    map<char,string> &getsettings();
    int readConfig();
    int writeConfig();
    ~DisplayConfig();
};

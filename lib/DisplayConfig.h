#include<fstream>
#include<iostream>
#include<sstream>
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
    map<string, int> settings;
    map<string, int>::iterator it;

    public:
    string defaults;
    DisplayConfig();
    map<string, int> &getsettings();
    void addToMap(const string ,const int);
    bool readConfig();
    int writeConfig();
    ~DisplayConfig();
};



//This Will Read The Configurations From A Formated Text
//File
//Display Configuration Manager
//Settings FileName = xconfig.dat

class DisplayConfig
{
    string defaults;
    public:
    DisplayConfig();
    int readConfig();
    int writeConfig();
    ~DisplayConfig();
};

#include"DisplayConfig.h"

map<char,string> &DisplayConfig::getsettings()
{
    return this->settings;
}
DisplayConfig::DisplayConfig()
{
       defaults =  "RESOLUTION 680x460\n";
       defaults +=   "DEPTH 32\n";
       defaults +=   "FULLSCREEN 0";

	   input.open("config/xconfig.dat");
	    if(!input.is_open())
	    {
		system("mkdir config");
		output.open("config/xconfig.dat",ios::out);
		output << defaults;
		
		output.close();
	    }

	    else
	    {
	    	if(!readConfig())
	    	{
	    	    cout<<"Problem with settings file"<<endl;
	    	    cout<<"Delete the file /config/xconfig.dat"<<endl;
	    	    cout<<"To Fix The Problem"<<endl;
	    	}
	    }



}

//scan the opened file
//for loading the settings
//into the settingsmap

int DisplayConfig::readConfig()
{
    while(!input.eof())
    {
       //input.getline();
    }
}
int DisplayConfig::writeConfig(){}
DisplayConfig::~DisplayConfig(){}



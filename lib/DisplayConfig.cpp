#include"DisplayConfig.h"

map<string, int> &DisplayConfig::getsettings()
{
    return this->settings;
}
DisplayConfig::DisplayConfig()
{
       defaults =  "height = 460\n";
       defaults +=  "width = 680\n";
       defaults +=   "bpp = 32\n";
       defaults +=   "fullscreen = 0\n";
       defaults +=   "sound = 0\n";


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
	    	if(input.is_open())
	    	{
                readConfig();
	    	}
	    	else
	    	{
	    	    cout<<"Problem with settings file"<<endl;
	    	    cout<<"Delete the file /config/xconfig.dat"<<endl;
	    	    cout<<"To Fix The Problem"<<endl;
	    	}
	    }

        if(input.is_open()) input.close();

}

void DisplayConfig::addToMap(const string key, const int value)
{
   settings.insert(pair<string, int>(key,value ));
}

//scan the opened file
//for loading the settings
//into the settingsmap

bool DisplayConfig::readConfig()
{
    size_t pos;
    string data ,key,value;
    int intvalue;
    std::stringstream ss;
    input.open("config/xconfig.dat");

        if(input.is_open())
        {
             while(getline(input,data))
            {

                pos= data.find_first_of("=");
                key = data.substr(0,pos);
                value = data.substr(pos+1);


                if((ss >> intvalue).fail())
                {
                    addToMap( key,intvalue );
                }
                else
                {
                    cout<<"Error reading configfile"<<endl;
                }
            }
        }
        input.close();
}

int DisplayConfig::writeConfig()
{
    if(!settings.empty())
    {
         for(it = settings.begin(); it != settings.end(); it++)
        {
            cout << (*it).first << " => " << (*it).second << endl;
        }
    }

}
DisplayConfig::~DisplayConfig()
{

}




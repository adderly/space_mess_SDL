#include<fstream>
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class Log
{
     ofstream ofile;
     ifstream check;
     string defaultDir;

     public:
     Log();
     Log(const string defaultLocation);
     void openf();
     void write_to_f(const string which,const string data);
     void closef();
     bool checkFolderExistance();
     ~Log();
};


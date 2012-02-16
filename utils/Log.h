#include<fstream>
#include<iostream>
#include<cstdlib>
#include<string>
#include<exception>



#ifndef LOG
#define LOG

using namespace std;
class Log
{
     std::ofstream ofile;
     std::ifstream check;
     std::string defaultDir;

     public:
     Log();
     Log(const string defaultLocation);
     void openf();
     void write_to_f(const string which,const string data);
     void closef();
     bool checkFolderExistance();
     ~Log();
};



static void saveLog(std::string data)
{
    Log* log = new Log();
    log->write_to_f("Testing",data);
}

#endif



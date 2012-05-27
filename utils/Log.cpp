#include"Log.h"

Log::Log()
{
    defaultDir = "logs/";
    checkFolderExistance();
}
Log::Log(const string defaultDir)
{
    this->defaultDir = defaultDir;
    checkFolderExistance();
}
Log::~Log()
{

}
bool Log::checkFolderExistance()
{
    string command = ("okay.txt");
    check.open((defaultDir+command).c_str(),ios::ios_base::out);
    if(check.is_open())
    {

    }
    else
    {
        std::cout<<"Did not existed!";
        std::cout<<"ummmm-->>"<< system(("mkdir "+defaultDir).c_str());
        //std::cout<<"eeehhmmm-->>"<< system("ls");
        check.open(command.c_str());
    }
    check.close();

}
void Log::closef()
{
    ofile.close();

}
void Log::openf() {}
void Log::write_to_f(const std::string whichone,const std::string data)
{
    ofile.open((defaultDir+whichone+".log").c_str(),std::ios_base::out|std::ios_base::app);

    if(ofile.is_open())
    {
        ofile<<data<<std::endl;
    }
    else
    {
        std::cout<<"DAmn";
    }
    ofile.close();

}




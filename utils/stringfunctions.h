#include<sstream>

#ifndef SF
#define SF
static std::string getFromInt(int number)
{

    stringstream ss;

    ss<<number<<".bmp";

    return ss.str();
}
#endif


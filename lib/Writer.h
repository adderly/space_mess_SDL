#include"Write.h"


#ifndef WRITER
#define WRITER

class Writer:public Write
{
    char buffer[256];//in case its needed
public:
    Writer();
    ~Writer();
};
#endif

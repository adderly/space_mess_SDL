#ifndef WRITE
#define WRITE

class Write
{
public:
    virtual void write(const std::string filename)=0;
    virtual void write(const std::string filename,const std::string location)=0;
    virtual bool checkExistance(const std::string filename,const std::string location)=0;
};
#endif




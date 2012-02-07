#include<string>

class Gun
{
    std::string name;
    int amoamout;
    float maxHeat;
    public:
    Gun();
        virtual void fire();
        void setName(std::string name);
    ~Gun();
};



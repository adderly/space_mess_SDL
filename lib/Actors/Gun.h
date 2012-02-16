#include<string>
#include"Weapon.h"

class Gun:public Weapon
{
    std::string name;
    float maxHeat;
    public:
    Gun();
        void fire();
        void setName(std::string name){this->name = name;}
        std::string getName(){return this->name;}
    ~Gun();
};



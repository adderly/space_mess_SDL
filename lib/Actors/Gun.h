#ifndef GUN
#define GUN

#include<string>
#include"Weapon.h"
namespace Actors
{
    class Gun:public Weapon
    {
        friend class Player;
        int ammoAmount;
        std::string name;
        float maxHeat;
    public:
        Gun();
        void fire();
        void setName(std::string name)
        {
            this->name = name;
        }
        std::string getName()
        {
            return this->name;
        }
        ~Gun();
    };
};
#endif

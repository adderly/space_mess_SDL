#include"Gun.h"

namespace Actors
{

    Gun::Gun():Weapon()
    {
        ammoAmount= 100;
    }

    void Gun::fire()
    {
        ammoAmount--;

    }
    Gun::~Gun()
    {
        delete &name;
        delete &maxHeat;
    }
};

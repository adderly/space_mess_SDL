#include"Gun.h"


Gun::Gun()
{

}

void Gun::fire()
{

}
Gun::~Gun()
{
    delete &name;
    delete &maxHeat;
}

#include"Gun.h"


Gun::Gun(){}
void Gun::setName(std::string name)
{
    this->name = name;
}
void Gun::fire()
{
    amoamout--;
}
Gun::~Gun()
{
    delete &name;
    delete &amoamout;
    delete &maxHeat;
}

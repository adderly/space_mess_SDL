#include<iostream>

typedef struct Guns
{

};

class Spaceship
{
    std::string name;
    bool shield;
    public:
    Spaceship();
    setName(std::string name){this->name = name;}
    virtual void PutShield();
    ~Spaceship();
};


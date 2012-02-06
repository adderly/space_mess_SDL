#include<vector>
#include<iostream>

typedef struct Guns
{

};

class Spaceship
{
    std::vector<Guns> guns;
    std::string name;
    bool shield;
    public:
    Spaceship();
    setName(std::string name){this->name = name;}
    virtual void PutShield();
    ~Spaceship();
};


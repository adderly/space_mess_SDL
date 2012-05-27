#ifndef WEAPON
#define WEAPON
class Weapon
{

    int MAX_AMMO_AMOUNT;
    float MAX_HEAT;
public:
    Weapon();
    virtual void fire()=0;
    int getAmmo()
    {
        return this->MAX_AMMO_AMOUNT;
    }

};


#endif


class Weapon
{
    int MAX_AMMO_AMOUNT;
    public:
    Weapon();
    virtual void fire()=0;
};

Weapon::Weapon(){}


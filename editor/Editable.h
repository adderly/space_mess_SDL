class Editable
{
public:
    bool _selected;
    virtual void changeSize() = 0;
    virtual void setBounds(float,float,float,float) = 0;
    virtual void move() = 0;
    virtual void select()
    {
        _selected = true;
    }
};


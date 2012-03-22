
class GFigure
{
    public:
    float _x,_y,_z;
};


class Triangle:public GFigure
{
    public:
    float _w,_h;
};
class Square:public GFigure
{
    public:
    float _w,_h;
};
class Cube:public GFigure
{
    public:
    float _w,_h;
};
class Piramide:public GFigure
{
     public:
    float _w,_h;

};
class Circle:public GFigure
{
     public:
    float _w,_h;//The H is in case you want an oval
};

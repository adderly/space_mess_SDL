#include "Container.h"
namespace Graphics
{
    Container::Container()
    {
    }
    Container::Container(vector<Drawable*>)
    {
    }
    void Container::draw()
    {
        Render::drawContainer(this);
    }
    void Container::addItem(Drawable* item)
    {
        this->items.push_back(item);
    }
    void Container::removeItem(Drawable* item){}

    Container::~Container(){}

}


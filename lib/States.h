
#ifndef STATES
#define STATES

class States
{
    bool _selected;
    bool _enabled;
    bool _visible;
    bool _draggable;
    bool _dropable;

    public:

    void setIsSelected(bool selected)
    {
        this->_selected = selected;
    }
    bool isSelected()
    {
        return this->_selected;
    }
    void setIsEnabled(bool enabled)
    {
        this->_enabled = enabled;
    }
    bool isEnabled()
    {
        return this->_enabled;
    }
    void setIsVisible(bool visible)
    {
        this->_visible = visible;
    }
    bool isVisible()
    {
        return this->_visible;
    }
    void setIsDraggable(bool draggable)
    {
        this->_draggable = draggable;
    }
    bool isDraggable()
    {
        return this->_draggable;
    }
    void setIsDropable(bool droppable)
    {
        this->_dropable = droppable;
    }
    bool isDropable()
    {
        return this->_dropable;
    }

};
#endif



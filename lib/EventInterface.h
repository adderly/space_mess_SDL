#include "sigc++/sigc++.h"

class EInterface{

    virtual void check()=0;
    virtual void check(SDL_Event&)=0;
    virtual void inline mouseOver() = 0;
    virtual void inline mouseDown() = 0;
    virtual void inline mouseUp() = 0;
    virtual void inline drag() = 0;
};


#ifndef EVENTS
#define EVENTS

class eventSignals : public sigc::trackable
{
    public:
    sigc::signal<void> s_clicked;
    sigc::signal<void> s_rightclicked;
    sigc::signal<void> s_selected;
    sigc::signal<void> s_mouseover;
    sigc::signal<void> s_drag;
    sigc::signal<void> s_drop;

    virtual void check() = 0;

    virtual void f_clicked() = 0;
    virtual void f_rightclicked() = 0;
    virtual void f_selected() = 0;
    virtual void f_mouseover() = 0;
    virtual void f_drag() = 0;
    virtual void f_drop() = 0;

};

#endif

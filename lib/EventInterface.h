#include "sigc++/sigc++.h"
#include<SDL/SDL.h>

#ifndef EINTERFACE
#define EINTERFACE
class EInterface
{

    virtual void check()=0;
    virtual void check(SDL_Event&)=0;
    virtual void inline mouseOver() = 0;
    virtual void inline mouseDown() = 0;
    virtual void inline mouseUp() = 0;
    virtual void inline drag() = 0;
};
#endif

#ifndef EVENTS
#define EVENTS
/*
    This class should contain, the necesary things that
    an object should have to be treated as a 'reactionable' entity
    The 's' preceding variables stand for 'signal'
    The 'f' preceding the functions stand for 'function' -_-
*/
class eventSignals : public sigc::trackable
{
public:
    bool clicked;
    bool rightclicked;
    bool selected;
    bool mouseover;
    bool drag;
    bool drop;// Guess it would never be used, cause you are never dropping things
    bool active; //the idea for this is

    sigc::signal<void> s_clicked;
    sigc::signal<void> s_rightclicked;
    sigc::signal<void> s_selected;
    sigc::signal<void> s_mouseover;
    sigc::signal<void> s_drag;
    sigc::signal<void> s_drop;

    eventSignals() {}
    virtual void check() = 0;

    virtual void f_clicked() = 0;
    virtual void f_rightclicked() = 0;
    virtual void f_selected() = 0;
    virtual void f_mouseover() = 0;
    virtual void f_drag() = 0;
    virtual void f_drop() = 0;

};

#endif

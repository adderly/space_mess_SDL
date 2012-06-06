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
    //Available events
    bool isClickable;
    bool isRightClickable;
    bool isSelectable;

    //States
    bool MOUSE_DOWN;
    bool MOUSE_UP;
    bool CLICKED;
    bool RIGHT_CLICKED;
    bool SELECTED;
    bool MOUSE_OVER;
    bool DRAG;
    bool DROP;// Guess it would never be used, cause you are never dropping things
    bool ACTIVE; //the idea for this is
    bool FOCUSED;

    sigc::signal<void> s_clicked;
    sigc::signal<void> s_rightclicked;
    sigc::signal<void> s_selected;
    sigc::signal<void> s_mouseover;
    sigc::signal<void> s_drag;
    sigc::signal<void> s_drop;
    sigc::signal<void> s_mouse_down;
    sigc::signal<void> s_mouse_up;

    eventSignals()
     {
         setClickCallBack(sigc::mem_fun(this,&eventSignals::hi));
     }
     template<class T,class K>  T setClickCallBack(sigc::bound_mem_functor0<T,K> toconnet)
     {
            s_clicked.connect(toconnet);
            this->isClickable = true;
     }

    template<class T,class K>  T setRightClickCallBack(sigc::bound_mem_functor0<T,K> toconnet)
     {
            s_rightclicked.connect(toconnet);
            this->isRightClickable = true;
     }
    template<class T,class K>  T setSelectCallBack(sigc::bound_mem_functor0<T,K> toconnet)
     {
            s_selected.connect(toconnet);
            this->isSelectable = true;
     }

    bool getIsSelected(){ return this->SELECTED;}
    void hi(){}
    virtual void check() = 0;

    virtual void f_clicked() = 0;
    virtual void f_rightclicked() = 0;
    virtual void f_selected() = 0;
    virtual void f_mouseover() = 0;
    virtual void f_drag() = 0;
    virtual void f_drop() = 0;

       /******************GENERIC EVENT CHECK*****************/
    /*check is the mouse is over the drawable taking mouse pos as parameter */
   virtual inline bool isOver(int,int) = 0;
   /******************************************************/

};

#endif

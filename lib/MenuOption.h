/*
    A menu have options, and this options have attributes.
    To make it clear an option of a menu may contain a pointer
    to a function
*/
/*  OPtion to be contained Inside A menu*/
#ifndef MENUOPTION
#define MENUOPTION
namespace Graphics
{

    typedef class MenuOption: public Drawable
    {
    public:
        unsigned int texture_id;
        static const float defaultwidth = 120;
        static const float defaultheight = 60;
        std::string text;
        bool enable, hasText;

        /******TExtBox and CheckBOX**********/
        bool isTextBox,isCheckBox;
        bool isSelected;
        /******TExtBox and CheckBOX**********/
        bool VOIDFUNC,INTVOIDFUNCT,KEYUPFUNC,KEYDOWNFUNC,MOUSEOVERFUNC;

        //callbacks
        void (*vfunc)();
        void (*func)(int);
        void (*keyDown)();
        void (*keyUp)();
        void (*mouseOver)();

        void setMouseOverCallBack(void (*m)())
        {
            mouseOver = m;
            MOUSEOVERFUNC = true;
        }
        void setKeyDownCallBack(void (*k)())
        {
            this->keyDown = k;
            KEYDOWNFUNC = true;
        }
        void setKeyUpCallBack(void (*k)())
        {
            this->keyUp = k;
            KEYUPFUNC = true;
        }
        void setVoidCallBack(void (*f)(int))
        {
            this->func = f;
            INTVOIDFUNCT =true;
        }
        void setVoidCallBack(void (*f)())
        {
            this->vfunc = f;
            VOIDFUNC = true;
        }

        MenuOption():Drawable(10,10,10,10)
        {
            this->enable = false;
        }
        MenuOption(float X,float Y,float W,float H):Drawable(X,Y,W,H)
        {
            this->x=X;
            this->y=Y;
            this->width=W;
            this->height=H;
            this->enable = false;
        }
        //Not Doing Anything
        virtual void draw() {}
    };
};
#endif


#include<string>

class Window{


    public:
   static const float width = 680.0,height = 480.0,bpp = 32;
    static std::string title;
    void setTitle(std::string Title){ title = Title;}
    std::string getTitle(){return title;}
    Window();
    ~Window();
};

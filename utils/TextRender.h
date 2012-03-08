#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>
 #include<iostream>
 #include<string>
 #include"Log.h"

class Text
{
    SDL_Surface* screen;
    SDL_Color textColor;
    std::string fontLocation;

    public:
    TTF_Font*    font;
    SDL_Surface* t;
    Text();
    Text(SDL_Surface &main);
    Text(SDL_Surface &texture,const std::string text);
    Text(SDL_Surface &texture,const std::string text,float **color);
    void init();
    void loadResources();
    void freeResources();
    void setFontLocation(std::string location){ this->fontLocation = location;}
    void setSurface(SDL_Surface* surface){ this->t = surface;}
    SDL_Surface* getSurface(){return this->t;}
    ~Text();
};




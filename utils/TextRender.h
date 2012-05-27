#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>
#include<iostream>
#include<sstream>
#include<string>
#include"Log.h"

namespace Images
{
#ifndef TEXT
#define TEXT


class Text
{
    SDL_Color textColor;
    std::string fontLocation;
    std::string text;
    int fontSize;
    bool bold;

public:
    TTF_Font*    font;
    SDL_Surface* tmp;
    Text();
    Text(std::string txt);
    Text(SDL_Surface* main);
    Text(SDL_Surface *texture,const std::string text,int size);
    Text(SDL_Surface *texture,const std::string text,SDL_Color color);
    SDL_Surface* generate();
    SDL_Surface* generate(const std::string text);
    SDL_Surface* generate(const std::string text,int size);
    SDL_Surface* generate(SDL_Surface *texture,const std::string text);
    SDL_Surface* generate(SDL_Surface *texture,const std::string text,int size);
    SDL_Surface* getSurface()
    {
        return this->tmp;
    }
    void init();
    void loadResources();
    void freeResources();
    void setFontLocation(std::string location)
    {
        this->fontLocation = location;
    }
    void setSurface(SDL_Surface* surface)
    {
        this->tmp = surface;
    }
    void setSize(int size)
    {
        this->fontSize = size;
    }
    int getSize()
    {
        return this->fontSize;
    }
    ~Text();
};
#endif
}

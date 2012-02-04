#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>

class Text
{
    SDL_Surface* screen;

    SDL_Color textColor;

    public:
    TTF_Font*    font;
    SDL_Surface* text;
    Text();
    Text(SDL_Surface &main);
    void loadResources();
    void freeResources();
    ~Text();
};



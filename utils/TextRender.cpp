#include"TextRender.h"

Text::Text()
{
    TTF_Init();
    textColor = {255,255,255};
    loadResources();
}
Text::Text(SDL_Surface &main)
{
    TTF_Init();
    textColor = {255,255,255};
    this->screen = &main;
    loadResources();
}
void Text::loadResources()
{
   font = TTF_OpenFont("resources/lazy.ttf", 45);
   //std::cout<<TTF_GetError();
    if(t == NULL) exit(0);
    SDL_Color c = {255,255,0};
   t = TTF_RenderText_Solid(font,"Fuck IT",c);

}
void Text::freeResources()
{
    TTF_CloseFont(font);
    TTF_Quit();
}
Text::~Text(){}




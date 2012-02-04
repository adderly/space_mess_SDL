#include"TextRender.h"

Text::Text()
{
    TTF_Init();
    textColor = {255,255,255};
    loadResources();
}
Text::Text(SDL_Surface &main)
{
    TTF_Init()-1;
    textColor = {255,255,255};
    this->screen = &main;
    loadResources();
}
void Text::loadResources()
{
   font = TTF_OpenFont("UbuntuMono-BI.ttf", 16);
    if(text == NULL) exit(0);
//   SDL_Color c = {255,0,0};
//   text = TTF_RenderText_Solid(font,"okay",c);

}
void Text::freeResources()
{
    TTF_CloseFont(font);
    TTF_Quit();
}
Text::~Text(){}




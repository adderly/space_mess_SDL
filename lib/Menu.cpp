#include"Menu.h"


Menu::Menu():Drawable(10,10,10,10)
{

    visible = true;
    gridoptions.spacing = 10.0;
    this->x = 0;
    this->y = 0;
    this->width = 450;
    this->height = 320;

    init();
}
Menu::Menu(float parentWidth,float parentHeight,float width,float height):Drawable(10,10,width,height)
{
    visible = true;
    gridoptions.spacing = 10.0;
    this->width = width;
    this->height = height;

    //Centering the menu
    this->x = (parentWidth/2)-(width/2);
    this->y = (parentHeight/2)-(height/2);
    //this->background = txt.generate(this->background,"OH YEAH");
    init();
}
//create some defaults options
void Menu::init()
{
    gridoptions.spacing = 10.0;
    gridoptions.columns = 3;
    int tmpy = this->y;
    int tmpx = this->x;
    int tmpw = 75;
    int tmph = 45;
    int counter = 0;
    for(int l= 0,n = 0; n<11;n++,tmpx+=75,counter++)
    {
      MenuOption *op = new MenuOption();

      op->width = tmpw;
      op->height = tmph;
      op->x = tmpx+l;

      if(counter == 3)
      {
          tmpy+=tmph;
          tmpx = this->x;
          counter = 0;
      }
      op->y = tmpy+l;
      op->text = "Option";
      op->background = SDL_DisplayFormatAlpha(IMG_Load("resources/images/brick.bmp"));
      op->enable = false;
      options.push_back(op);
    }
}
void Menu::setUpItems()
{
    int amount = (int)options.size();

}
void Menu::check()
{
    while(SDL_PollEvent(event))
    {
        if(event->type == SDL_MOUSEMOTION)
        {
            mouseOver();
        }
        if(event->type == SDL_MOUSEBUTTONDOWN)
        {
            mouseDown();
        }
        if(event->type == SDL_MOUSEBUTTONUP)
        {
              switch(event->key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    visible = false;
                break;
                default:
                break;
            }
            mouseUp();
        }
    }
}
void Menu::drag()
{
}
void Menu::mouseOver()
{
    for(it = options.begin();it != options.end();it++)
    {
        if(event->motion.x >= (**it).x && event->motion.x <= (**it).x + (**it).width)
        {
            if(event->motion.y >= (**it).y && event->motion.y <= (**it).y+(**it).height)
            {
                (**it).enable = true;
            }
            else (**it).enable = false;
        }
        else (**it).enable = false;
    }

}
void Menu::mouseDown()
{
    for(it=options.begin();it != options.end();it++)
    {
        if((**it).enable) (**it).func();
    }
}
void Menu::mouseUp()
{
     for(it=options.begin();it != options.end();it++)
    {
        if((**it).enable) (**it).func();
    }
}
void Menu::draw()
{
   // glColor4ub(0,0,0,255);
    glColor3f(1,1,1);
     glBegin(GL_QUADS);
            glVertex2f(x,y);
            glVertex2f(x+width,y);
            glVertex2f(x+width,y+height);
            glVertex2f(x,y+height);
     glEnd();
    SDL_BlitSurface(background,NULL,ParentBackground,NULL);
            SDL_UpdateRect(ParentBackground,x,y,width,height);

    if(!options.empty())
    {
        //Print Options
        for(it = options.begin();it != options.end();it++)
        {
            if((**it).enable == true)glColor3f(1,0,0);
            else glColor3f(1,1,1);
            glBegin(GL_QUADS);
            glVertex2f((**it).x+gridoptions.spacing,(**it).y);
            glVertex2f((**it).x+(**it).width,(**it).y);
            glVertex2f((**it).x+(**it).width,(**it).y+(**it).height);
            glVertex2f((**it).x,(**it).y+(**it).height);
            glEnd();
            if((**it).background != NULL)
            {
               SDL_BlitSurface((**it).background,NULL,background,NULL);
               SDL_UpdateRect(background,(**it).x,(**it).y,(**it).background->w,(**it).background->h);

            }

        }

    }

}
Menu::~Menu(){}



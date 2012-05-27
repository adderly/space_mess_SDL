#include"Menu.h"
namespace Graphics
{


Menu::Menu():Drawable(10,10,10,10)
{

    visible = true;
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
    init();
}
void Menu::setUpOption(MenuOption* opt)
{
    opt->texture_id = imgr.gen(opt->text,SDL_DisplayFormatAlpha(txt.generate(opt->text,20)));

}
void Menu::addOption(MenuOption* opt)
{
    setUpOption(opt);
    options.push_back(opt);
}
//create some defaults options
void Menu::init()
{
    /*------------Menu Defaults Options--------*/
    //BackButton
    MenuOption *ba =  new MenuOption((this->x+this->width)-120,this->height-60,120,60);
    ba->enable = false;
    ba->background = SDL_DisplayFormatAlpha(txt.generate(this->background,"EH aqui la cosa",50));
    ba->texture_id = imgr.gen(ba->text,ba->background);
    ba->func = std::exit;
    options.push_back(ba);


    /*-----------------------------------------*/

    gridoptions.spacing = 10.0;
    gridoptions.columns = 3;
    int tmpy = this->y;
    int tmpx = this->x;
    int tmpw = 75;
    int tmph = 45;
    int counter = 0;
    for(int n = 0; n<11; n++,tmpx+=75,++counter)
    {
        MenuOption *op = new MenuOption();
        if(counter == gridoptions.columns)
        {
            tmpy+=tmph;
            tmpx = this->x;
            counter = 0;
        }
        op->width = tmpw;
        op->height = tmph;
        op->x = tmpx;
        op->y = tmpy;
        op->text = "Option";
        op->background = SDL_DisplayFormatAlpha(txt.generate(this->background,"EH aqui la cosa"));
        op->texture_id = imgr.gen(op->text,op->background);
        op->enable = false;
        op->func = std::exit;
        options.push_back(op);
    }
    this->setBackground(SDL_DisplayFormatAlpha(txt.generate(this->background,"EH aqui la cosa")));

}
void Menu::setUpItems()
{
    /*This is where items will be ordered
        acording to the grid properties
    */
    int amount = 0;
    int total_items_width;
    int total_items_height;

    for(it =  options.begin(); it != options.end(); it++)
    {
        if((*it)->text != "exit")
        {
            total_items_width+=((*it)->width+gridoptions.spacing);
            total_items_height+=((*it)->height+gridoptions.spacing);
        }
    }

    int item_rows = total_items_width/(this->width-100);
    int item_per_row = total_items_width/(this->width-100);
    it = options.begin();
    int h_spaccing_tmp = (**it).height;
    for( int n_items = item_rows; it!=options.end(); it++,n_items--)
    {
        for(int row_no = 0; row_no < item_rows; row_no++)
        {

        }


    }

}
void Menu::check() {}
void Menu::check(SDL_Event &e)
{
    this->event = &e;

    if(event->type == SDL_MOUSEMOTION)
    {
        mouseOver();
    }
    else if(event->type == SDL_MOUSEBUTTONDOWN )
    {
        mouseDown();
    }
    if(event->type == SDL_MOUSEBUTTONUP )
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
void Menu::drag()
{

}
void Menu::mouseOver()
{
    for(it = options.begin(); it != options.end(); it++)
    {
        if(event->motion.x >= (**it).x && event->motion.x <= (**it).x + (**it).width)
        {
            if(event->motion.y >= (**it).y && event->motion.y <= (**it).y+(**it).height)
            {
                (**it).enable = true;
                someOptionEnabled = true;

                // if((**it).MOUSEOVERFUNC) (**it).mouseOver();
            }
            else
            {
                (**it).enable = false;
                someOptionEnabled = false;
            }
        }
        else
        {
            (**it).enable = false;
            someOptionEnabled = false;
        }
    }

}
void Menu::mouseDown()
{
    if(someOptionEnabled)
        for(it=options.begin(); it != options.end(); it++)
        {
            if((**it).enable== true) (**it).func(0);
        }
}
void Menu::mouseUp()
{
    if(someOptionEnabled);
    for(it=options.begin(); it != options.end(); it++)
    {
        if((**it).enable) (**it).vfunc();

    }
}
void Menu::draw()
{
    glColor4f(color[0],color[1],color[2],color[3]);
    glBegin(GL_QUADS);
    glVertex2f(x,y);
    glVertex2f(x+width,y);
    glVertex2f(x+width,y+height);
    glVertex2f(x,y+height);
    glEnd();
    glColor4f(1,1,0,0.5);
    glBegin(GL_LINES);
    //top
    glVertex2f(x,y);
    glVertex2f(x+width,y);
    //leftBorder
    glVertex2f(x,y);
    glVertex2f(x,y+height);
    //right border
    glVertex2f(x+width,y);
    glVertex2f(x+width,y+height);

    //bottom border
    glVertex2f(x,y+height);
    glVertex2f(x+width,y+height);
    glEnd();
    if(!options.empty())
    {
        glEnable(GL_TEXTURE_2D);
        //Print Options
        for(it = options.begin(); it != options.end(); it++)
        {
            if((**it).enable == true)
            {
                glColor4f(1,0,0,1.0);
            }
            else
            {
                glColor4f(1,1,0,1.0);
            }

            glBindTexture(GL_TEXTURE_2D,(**it).texture_id);
            glBegin(GL_QUADS);
            glVertex2f((**it).x+gridoptions.spacing,(**it).y);
            glTexCoord2f(1.0,0.0);
            glVertex2f((**it).x+(**it).width+gridoptions.spacing,(**it).y);
            glTexCoord2f(1.0,1.0);
            glVertex2f((**it).x+(**it).width+gridoptions.spacing,(**it).y+(**it).height);
            glTexCoord2f(0.0,1.0);
            glVertex2f((**it).x+gridoptions.spacing,(**it).y+(**it).height);
            glTexCoord2f(0.0,0.0);
            glEnd();
        }
        glDisable(GL_TEXTURE_2D);
    }

}
void Menu::setVisible(bool value)
{
    this->visible = value;
}
void Menu::setExitOption(MenuOption* o)
{
    exit = o;
    exit->x = this->width - exit->width;
    exit->y = this->height - exit->height;
    options.push_back(exit);
}
void Menu::setBackOption(MenuOption* o)
{
    back = o;
    back->x = this->width - back->width;
    back->y = this->height - back->height;
    options.push_back(back);
}

Menu::~Menu()
{
    delete &imgr;
}


}

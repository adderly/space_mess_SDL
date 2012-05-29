#include"Drawable.h"


void Drawable::f_clicked()
 {
     this->s_clicked.emit();
 }
void Drawable::f_rightclicked() {}
void Drawable::f_selected() {}
void Drawable::f_mouseover() {}
void Drawable::f_drag() {}
void Drawable::f_drop() {}
void Drawable::check() {}

    /******************GENERIC EVENT CHECK*****************/
    /*check is the mouse is over the drawable taking mouse pos as parameter */
  bool Drawable::isOver(int x ,int y)
    {
        if(x >= this->x && x <= this->x + this->width)
        {
            return true;
        }
        return false;
    }
   /******************************************************/



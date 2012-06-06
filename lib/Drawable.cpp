#include"Drawable.h"

namespace Graphics
{
    void Drawable::f_clicked()
     {
         this->s_clicked.emit();
     }
    void Drawable::f_rightclicked()
     {

     }
    void Drawable::f_selected() {}
    void Drawable::f_mouseover() {}
    void Drawable::f_drag() {}
    void Drawable::f_drop() {}
    void Drawable::check() {}

    void Drawable::draw()
    {
            if(this->SELECTED)  glColor4f(1,selectedColor[1],selectedColor[2],selectedColor[3]);
            else if( this->MOUSE_OVER)  glColor4f(selectedColor[0],selectedColor[1],selectedColor[2],selectedColor[3]);
            else    glColor4f(color[0],color[1],color[2],color[3]);



            if(this->isQuad)
            {
                    glBegin(GL_QUADS);
                    glVertex3f(this->x,this->y,this->z);
                    glVertex3f(this->x+this->width,this->y,this->z);
                    glVertex3f(this->x+this->width,this->y+this->height,this->z);
                    glVertex3f(this->x,this->y+this->height,this->z);
                    glEnd();
            }
            else
            {
                    glBegin(GL_TRIANGLES);
                    glVertex3f(this->x+(this->width/2),this->y,this->z);
                    glVertex3f(this->x+this->width,this->y+this->height,this->z);
                    glVertex3f(this->x,this->y+this->height,this->z);
                    glEnd();
            }


    }

        /******************GENERIC EVENT CHECK*****************/
        /*check is the mouse is over the drawable taking mouse pos as parameter */
    // TODO (moisex#1#): Fix the mouse over, for non quads elements
      bool Drawable::isOver(int x ,int y)
        {
            if(x >= this->x && x <= this->x + this->width)
            {
               if(y >= this->y && y <= this->y + this->height)
                return true;
            }
            return false;
        }
       /******************************************************/

};

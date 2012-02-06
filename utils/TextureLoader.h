#include<SDL/SDL.h>
#include<SDL/SDL_opengl.h>


static unsigned int loadTexture(const char* filename)
{
    unsigned int id;
    SDL_Surface* img = SDL_LoadBMP(filename);
    glGenTextures(1,&id);
    glBindTexture(GL_TEXTURE_2D,id);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,img->w,img->h,0,GL_RGB,GL_UNSIGNED_SHORT_5_6_5,img->pixels);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    SDL_FreeSurface(img);

    return id;
}


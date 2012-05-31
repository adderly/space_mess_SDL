#include<SDL/SDL.h>
#include<SDL/SDL_opengl.h>
#include<SDL/SDL_image.h>

#ifndef LOADTEXTURE
#define LOADTEXTURE

namespace Graphics
{
    namespace Image
    {
        static unsigned int loadTexture(const char* filename)
        {
            unsigned  id(0);
            SDL_Surface* img = IMG_Load(filename);
            img = SDL_DisplayFormatAlpha(img);
            glGenTextures(1,&id);
            glBindTexture(GL_TEXTURE_2D,id);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,img->w,img->h,0,GL_RGBA,GL_UNSIGNED_INT_8_8_8_8_REV,img->pixels);

            SDL_FreeSurface(img);

            return id;
        }
    };

};
#endif;


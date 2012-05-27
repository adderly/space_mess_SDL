#include"ImageManager.h"

namespace Images
{

ImageManager::ImageManager()
{

}
ImageManager::~ImageManager() {}
inline void ImageManager::generate()
{

}
void ImageManager::add(const std::string name,unsigned int id)
{
    textures.insert(pair<std::string,unsigned int>(name,id));
}
unsigned int ImageManager::getTextureByName(const std::string name)
{
    it = textures.find(name);
    if(it == textures.end()) return 404;
    else return (*it).second;
}
void   ImageManager::generate(const std::string location,const std::string name)
{
    SDL_Surface* img = IMG_Load(location.c_str());
    img = SDL_DisplayFormatAlpha(img);
    glGenTextures(1,&actual);
    glBindTexture(GL_TEXTURE_2D,actual);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    if(img->format->BitsPerPixel == 32)
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,img->w,img->h,0,GL_RGBA,GL_UNSIGNED_BYTE,img->pixels);
    else glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,img->w,img->h,0,GL_RGBA,GL_UNSIGNED_BYTE,img->pixels);

    SDL_FreeSurface(img);
    add(name,actual);
}
void ImageManager::generate(const std::string name, SDL_Surface* src)
{

    glGenTextures(1,&actual);
    glBindTexture(GL_TEXTURE_2D,actual);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    if(src->format->BitsPerPixel == 32)
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,src->w,src->h,0,GL_RGBA,GL_UNSIGNED_BYTE,src->pixels);
    else glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,src->w,src->h,0,GL_RGBA,GL_UNSIGNED_BYTE,src->pixels);

    add(name,actual);
}
unsigned int ImageManager::gen(const std::string name,const std::string location)
{
    SDL_Surface* img = IMG_Load(location.c_str());
    img = SDL_DisplayFormatAlpha(img);
    glGenTextures(1,&actual);
    glBindTexture(GL_TEXTURE_2D,actual);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    if(img->format->BitsPerPixel == 32)
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,img->w,img->h,0,GL_RGBA,GL_UNSIGNED_BYTE,img->pixels);
    else glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,img->w,img->h,0,GL_RGBA,GL_UNSIGNED_BYTE,img->pixels);

    add(name,actual);

    SDL_FreeSurface(img);
    return actual;
}
unsigned int ImageManager::gen(const std::string name, SDL_Surface* src)
{
    glGenTextures(1,&actual);
    glBindTexture(GL_TEXTURE_2D,actual);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    if(src->format->BitsPerPixel == 32)
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,src->w,src->h,0,GL_RGBA,GL_UNSIGNED_BYTE,src->pixels);
    else glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,src->w,src->h,0,GL_RGBA,GL_UNSIGNED_BYTE,src->pixels);

    add(name,actual);
    return actual;
}
}

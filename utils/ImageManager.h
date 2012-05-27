#include<map>
#include<string>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_opengl.h>
#include"Log.h"
//generating images and textures

namespace Images
{
#ifndef IMAGE
#define IMAGE
class ImageManager
{
    std::map<std::string,unsigned int> textures;//GLTextures name,id
    std::map<std::string,unsigned int>::iterator it;
    unsigned int actual;
public:
    ImageManager();
    void add(const std::string name,unsigned int id);
    unsigned int getTextureByName(const std::string name);
    void generate(const std::string location,const std::string name);
    void generate(const std::string name, SDL_Surface* src);
    unsigned int gen(const std::string ,const std::string);
    unsigned int gen(const std::string name, SDL_Surface* src);
    inline void generate();
    ~ImageManager();

};
#endif
}


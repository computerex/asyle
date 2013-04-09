#ifndef _H_COMPUTEREX_H_TEXTURE_MANAGER_H_
#define _H_COMPUTEREX_H_TEXTURE_MANAGER_H_

#include <vector>
#include <map>
#include <string>
#include "texture.h"

class TextureManager
{
        public:
                TextureManager();
                ~TextureManager();
                bool loadtexture(std::string fname, std::string name);
                int  gettex(std::string name);
                bool textureexists(std::string name);
        private:
                std::map<std::string, Texture*> textures;        
};

#endif


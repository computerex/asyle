#ifndef _H_COMPUTEREX_H_TEXTURE_MANAGER_H_
#define _H_COMPUTEREX_H_TEXTURE_MANAGER_H_

#include <vector>
#include <map>
#include <string>
#include "texture.h"

class TextureManager
{
        public:
                
               static TextureManager* getTextureManager()
                {
                        if ( instance == 0 )
                                instance=new TextureManager();
                        return instance;
                }
                bool loadtexture(std::string fname, std::string name);
                void removeTexture(std::string name);
                void removeTexture(std::map<std::string,Texture*>::iterator itt);
                int  gettex(std::string name);
                bool textureexists(std::string name);
                void cleanup();
        private:
                // singleton
                TextureManager();
                ~TextureManager();
                std::map<std::string, Texture*> textures;  
                static TextureManager * instance;
};

#endif


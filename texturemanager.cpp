#include "texture.h"
#include "texturemanager.h"
#include "tgaloader.h"
#include <map>
#include <string>
#include <stdio.h>

TextureManager* TextureManager::instance = 0;

bool TextureManager::textureexists(std::string name)
{
        std::map<std::string,Texture*>::iterator itt = textures.begin();
        return (textures.find(name) != textures.end());
}

bool TextureManager::loadtexture(std::string fname, std::string name)
{
        if ( fname.length() == 0 || name.length() == 0 ) return false;
        if ( textureexists(name) ) return false; // texture name has to be unique
        // TODO handle file types other than targa
        TGAFILE tgafile; // will scope out and delete the image data
        if ( !loadtga(fname.c_str(), &tgafile) )
                return false;
         // create texture
        textures[name] = new Texture(tgafile.imageData, tgafile.imageWidth, tgafile.imageHeight);
        return true;
}

void TextureManager::cleanup()
{
        std::map<std::string,Texture*>::iterator itt; 
        Texture* texture;
        while ( !textures.empty() )
        {
                if ( itt == textures.end() )
                        printf("wtf is going on\n");
                itt=textures.begin();
                std::string key = itt->first;
                printf("Deleting %s\n", key.c_str());
                texture=itt->second;
                delete texture;
                texture=0;
                textures.erase(itt);
        }
}

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
        cleanup();
        // set instance to zeeerooo
        instance=0;
}

int TextureManager::gettex(std::string name)
{
        if ( !textureexists(name) )
         return 0;
        return textures[name]->getid();
}
void TextureManager::removeTexture(std::map<std::string, Texture*>::iterator itt)
{
        if ( itt != textures.end() ){
                Texture* tex = itt->second;
                printf("removeTexture: Deleting %s\n", itt->first.c_str());
                delete tex;
                tex=0;
                textures.erase(itt);
       }
}
void TextureManager::removeTexture(std::string name)
{
        if ( textureexists(name) ) {
                std::map<std::string, Texture*>::iterator itt = textures.find(name);
                removeTexture(itt);
        }
}


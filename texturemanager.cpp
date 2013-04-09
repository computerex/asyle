#include "texture.h"
#include "texturemanager.h"
#include "tgaloader.h"
#include <map>
#include <string>
#include <stdio.h>

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

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
        std::map<std::string,Texture*>::iterator itt; 
        Texture* texture;
        while ( !textures.empty() )
        {
                itt=textures.begin();
                texture=itt->second;
                delete texture;
                texture=0;
                textures.erase(itt);
        }
}

int TextureManager::gettex(std::string name)
{
        if ( !textureexists(name) )
         return 0;
        return textures[name]->getid();
}


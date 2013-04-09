#ifndef _H_COMPUTEREX_H_SKYBOX_H_
#define _H_COMPUTEREX_H_SKYBOX_H_

#include <string>
#include "Object.h"

class Skybox : Object
{
        public:
                enum SkyboxSides { SKYBOX_UP, SKYBOX_DOWN, SKYBOX_LEFT, SKYBOX_RIGHT, SKYBOX_FRONT, SKYBOX_BACK, SKYBOX_NSIDES };
                Skybox(std::string frontFile, std::string backFile,
                       std::string upFile, std::string downFile, 
                       std::string leftFile, std::string rightFile, std::string skyboxname);
                ~Skybox();
                
                void draw();
       private:
            TextureManager* texturemanager;
            std::string fileNames[SKYBOX_NSIDES];
            std::string ids[SKYBOX_NSIDES];
            std::string skyboxname;
};

#endif

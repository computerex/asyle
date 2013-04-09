#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include "skybox.h"



Skybox::Skybox(std::string frontFile, std::string backFile,
                       std::string upFile, std::string downFile, 
                       std::string leftFile, std::string rightFile, std::string skyboxname) : Object()
{
        texturemanager=TextureManager::getTextureManager();
        if ( texturemanager == 0 ) {
                printf("SKYBOX: Texture Manager loading failure\n");
                exit(1);
                return;
        }
        this->skyboxname=skyboxname;
        fileNames[SKYBOX_UP] = upFile;
        fileNames[SKYBOX_DOWN] = downFile;
        fileNames[SKYBOX_LEFT] = leftFile;
        fileNames[SKYBOX_RIGHT] = rightFile;
        fileNames[SKYBOX_FRONT] = frontFile;
        fileNames[SKYBOX_BACK] = backFile;
        
        ids[SKYBOX_UP] = skyboxname+upFile;
        ids[SKYBOX_DOWN] = skyboxname+downFile;
        ids[SKYBOX_LEFT] = skyboxname+leftFile;
        ids[SKYBOX_RIGHT] = skyboxname+rightFile;
        ids[SKYBOX_FRONT] = skyboxname+frontFile;
        ids[SKYBOX_BACK] = skyboxname+backFile;
        
        for ( unsigned int i = 0; i < SKYBOX_NSIDES; i++ )
        {
                if ( !texturemanager->loadtexture(fileNames[i], ids[i]) ) {
                        printf("Error loading %s\n", fileNames[i].c_str());
                }
        }
}       
                     
Skybox::~Skybox()
{
        // clean up the textures!
        for ( unsigned int i = 0; i < SKYBOX_NSIDES; i++ )
        {
                texturemanager->removeTexture(ids[i]);
        }
}

void Skybox::draw()
{
        double D = 25.;
        
        glDisable(GL_DEPTH_TEST);
        glDepthMask(false);
        
        // assume we're working with the modelview
        glPushMatrix();
        glLoadIdentity();
        //glRotatef(rot.x, 1,0,0);
        //glRotatef(rot.y, 0,1,0);
        //glRotatef(rot.z, 0,0,1);
        glColor3f(1,1,1);
        /* Sides */
        glBindTexture(GL_TEXTURE_2D, texturemanager->gettex(ids[SKYBOX_RIGHT]));
         glBegin(GL_QUADS);
          glTexCoord2f(0,0); glVertex3f(-D,-D,-D);
          glTexCoord2f(1,0); glVertex3f(+D,-D,-D);
          glTexCoord2f(1,1); glVertex3f(+D,+D,-D);
          glTexCoord2f(0,1); glVertex3f(-D,+D,-D);
         glEnd();
       glBindTexture(GL_TEXTURE_2D,texturemanager->gettex(ids[SKYBOX_FRONT]));
         glBegin(GL_QUADS);
          glTexCoord2f(0,0); glVertex3f(+D,-D,-D);
          glTexCoord2f(1,0); glVertex3f(+D,-D,+D);
          glTexCoord2f(1,1); glVertex3f(+D,+D,+D);
          glTexCoord2f(0,1); glVertex3f(+D,+D,-D);
         glEnd();
       glBindTexture(GL_TEXTURE_2D,texturemanager->gettex(ids[SKYBOX_LEFT]));
         glBegin(GL_QUADS);
          glTexCoord2f(0,0); glVertex3f(+D,-D,+D);
          glTexCoord2f(1,0); glVertex3f(-D,-D,+D);
          glTexCoord2f(1,1); glVertex3f(-D,+D,+D);
          glTexCoord2f(0,1); glVertex3f(+D,+D,+D);
         glEnd();
         glBindTexture(GL_TEXTURE_2D,texturemanager->gettex(ids[SKYBOX_BACK]));
         glBegin(GL_QUADS);
          glTexCoord2f(0,0); glVertex3f(-D,-D,+D);
          glTexCoord2f(1,0); glVertex3f(-D,-D,-D);
          glTexCoord2f(1,1); glVertex3f(-D,+D,-D);
          glTexCoord2f(0,1); glVertex3f(-D,+D,+D);
         glEnd();
         
  /* Top and Bottom */
         glBindTexture(GL_TEXTURE_2D,texturemanager->gettex(ids[SKYBOX_UP]));
         glBegin(GL_QUADS);
          glTexCoord2f(0,0); glVertex3f(-D,+D,-D);
          glTexCoord2f(1,0); glVertex3f(+D,+D,-D);
          glTexCoord2f(1,1); glVertex3f(+D,+D,+D);
          glTexCoord2f(0,1); glVertex3f(-D,+D,+D);
         glEnd();
         glBindTexture(GL_TEXTURE_2D,texturemanager->gettex(ids[SKYBOX_DOWN]));
         glBegin(GL_QUADS);
          glTexCoord2f(1,1); glVertex3f(+D,-D,-D);
          glTexCoord2f(0,1); glVertex3f(-D,-D,-D);
          glTexCoord2f(0,0); glVertex3f(-D,-D,+D);
          glTexCoord2f(1,0); glVertex3f(+D,-D,+D);
         glEnd();
                
        glPopMatrix();
        glDepthMask(true);
        glEnable(GL_DEPTH_TEST);
}


#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "texturemanager.h"
#include "skybox.h"

TextureManager* texturemanager = TextureManager::getTextureManager();
Skybox* skybox;
SDL_Surface* screen;

int gwidth=800;
int gheight=600;

// SDL destroys the current opengl context upon resizing T_T
// wtf is this
void cleanup()
{
        delete skybox;
        skybox=0;
        texturemanager->cleanup();
}

void init()
{
        glClearColor(0.5,0.5,0.5,1.0);
        glClearDepth(1.0f);
        glViewport(0,0,gwidth,gheight);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(50,gwidth/gheight,1.0,500.0);
        glMatrixMode(GL_MODELVIEW);
        
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
        glShadeModel( GL_SMOOTH );
        
        /* Culling. */
        glCullFace( GL_BACK );
        glFrontFace( GL_CCW );
        glEnable( GL_CULL_FACE );
        
        glEnable(GL_TEXTURE_2D);                        
        glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  
        glTexEnvf (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        
         char textures[6][24] = 
         {
                "miramar_ft.tga",
                "miramar_dn.tga",
                "miramar_bk.tga",
                "miramar_lf.tga",
                "miramar_rt.tga",
                "miramar_up.tga"
           };
    skybox=new Skybox("miramar_ft.tga", "miramar_bk.tga",
                       "miramar_up.tga", "miramar_dn.tga", 
                       "miramar_lf.tga", "miramar_rt.tga", "Skybox");
        //glEnable(GL_LIGHTING);
        //glEnable(GL_LIGHT0);
        //float col[]={1.0,1.0,1.0,1.0};
        //glLightfv(GL_LIGHT0,GL_DIFFUSE,col);
}
 
void display()
{
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        skybox->draw();
        //float pos[]={-1.0,1.0,-2.0,1.0};
        //glLightfv(GL_LIGHT0,GL_POSITION,pos);
        //glTranslatef(0.0,-30.0,-100.0);
        //glCallList(cube);       //and display it
}
 
 
int main(int argc,char** argv)
{
        SDL_Init(SDL_INIT_EVERYTHING);
        screen=SDL_SetVideoMode(gwidth,gheight,32,SDL_SWSURFACE|SDL_OPENGL|SDL_RESIZABLE);
        bool running=true;
        Uint32 start;
        SDL_Event event;
        init();
        while(running)
        {
                start=SDL_GetTicks();
                while(SDL_PollEvent(&event))
                {
                        switch(event.type)
                        {
                                case SDL_QUIT:
                                        printf("quittin\n");
                                        running=false;
                                        break;
                                case SDL_VIDEORESIZE:
                                        gwidth=event.resize.w;
                                        gheight=event.resize.h;
                                        cleanup();
                                        SDL_FreeSurface(screen);
                                        screen=SDL_SetVideoMode(gwidth,gheight,32,SDL_SWSURFACE|SDL_OPENGL|SDL_RESIZABLE);
                                        init();
                                        break;
                                        
                        }
                }
                display();
                SDL_GL_SwapBuffers();
                SDL_Delay(100);
        }
        cleanup();
        SDL_FreeSurface(screen);
        SDL_Quit();
        return 0;      
}

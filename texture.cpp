#include <GL/gl.h>
#include <GL/glu.h>
#include "texture.h"


Texture::Texture(const unsigned char * imgdata, int width, int height)
{
        // name texture
        glGenTextures( 1, (GLuint*)&texid );
        glBindTexture( GL_TEXTURE_2D, texid );
        glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        // the texture wraps over at the edges (repeat)
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
        gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, imgdata);
        glBindTexture(GL_TEXTURE_2D, 0);
}
Texture::~Texture()
{
        glDeleteTextures(1,(GLuint*)&texid);
}

int Texture::getid()
{
        return texid;
}

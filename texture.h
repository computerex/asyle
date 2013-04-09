#ifndef _H_COMPUTEREX_TEXTURE_H_
#define _H_COMPUTEREX_TEXTURE_H_

class Texture
{
        public: 
                Texture(const unsigned char * imgdata, int width, int height);
                ~Texture();
                int getid();
        private:
              int texid;
};

#endif

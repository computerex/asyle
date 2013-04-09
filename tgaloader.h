#ifndef _H_TGA_LOADER_H_
#define _H_TGA_LOADER_H_

class TGAFILE
{
        public:
            TGAFILE();
            ~TGAFILE();
            unsigned char imageTypeCode;
            short int imageWidth;
            short int imageHeight;
            unsigned char bitCount;
            unsigned char *imageData;
};


bool loadtga(const char *filename, TGAFILE * tgaFile);

#endif


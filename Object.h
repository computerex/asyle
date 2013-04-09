#ifndef _H_COMPUTEREX_OBJECT_ASYLE_H_
#define _H_COMPUTEREX_OBJECT_ASYLE_H_

#include "texturemanager.h"
#include "asylemath.h"

// static object 
#define OBJECT_TYPE_STATIC    0

// focusable 
#define OBJECT_TYPE_FOCUSABLE 1
 
typedef int AsyleObjectType;


class Object
{
        public:
                AsyleObjectType type;
                char name[256];
                VECTOR3 pos, rot; 
          void draw(); 
};


#endif

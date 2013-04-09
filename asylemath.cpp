#include <math.h>
#include "asylemath.h"


VECTOR3::VECTOR3(double x, double y, double z)
{
        this->x=x;
        this->y=y;
        this->z=z;
}
VECTOR3::VECTOR3()
{
        x=y=z=0;
}
double VECTOR3::length()
{
        return sqrt(x*x+y*y+z*z);
}

VECTOR3 VECTOR3::normalize()
{
        double len = length();
        return VECTOR3(x/len, y/len, z/len);
}




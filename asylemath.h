#ifndef _H_COMPUTEREX_ASYLE_MATH_H_
#define _H_COMPUTEREX_ASYLE_MATH_H_


class VECTOR3
{
        public:
                VECTOR3(double x, double y, double z);
                VECTOR3();
                double length();
                VECTOR3 normalize();
        double x, y, z;
};


#endif


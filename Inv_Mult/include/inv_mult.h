#ifndef INV_MULT_H
#define INV_MULT_H
#include <NTL/ZZ.h>

using namespace NTL;

class inv_mult
{
    public:
        inv_mult(ZZ,ZZ);
        ZZ get_result();

        ZZ a,n;
};

#endif // INV_MULT_H

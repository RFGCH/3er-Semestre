#ifndef MAT_H
#define MAT_H
#include <NTL/ZZ.h>

using namespace NTL;

class mat
{
    public:

        mat();
        ZZ resto_chino(ZZ,ZZ,ZZ,ZZ);
        ZZ inv_mult(ZZ,ZZ);
        ZZ mcd(ZZ,ZZ);
        ZZ pow(ZZ,ZZ,ZZ);
        ZZ mod(ZZ,ZZ);

};

#endif // MAT_H

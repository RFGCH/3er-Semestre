#ifndef MAT_H
#define MAT_H
#include <NTL/ZZ.h>
#include <vector>

using namespace NTL;
using namespace std;

class mat
{
    public:

        mat();
        ZZ resto_chino(ZZ,ZZ,ZZ,ZZ);
        ZZ inv_mult(ZZ,ZZ);
        ZZ mcd(ZZ,ZZ);
        ZZ pow_mod(ZZ,ZZ,ZZ);
        ZZ pow(ZZ,ZZ);
        ZZ mod(ZZ,ZZ);
        ZZ Primo_n_Bits(ZZ);
        bool Miller_Rabin(ZZ,ZZ);
        bool Miller_Test(ZZ,ZZ);

};

#endif // MAT_H

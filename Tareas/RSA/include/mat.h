#ifndef MAT_H
#define MAT_H
#include <windows.h>//temperatura y tiempo
#include <NTL/ZZ.h>

using namespace NTL;

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
        ZZ Random(int);
        int* DES_Test(int*,int);
        int* RC4();
        int* Secuencia_cifrante(int* S);
        int getheat();
        int gettime();
        int gettime2();

};

#endif // MAT_H

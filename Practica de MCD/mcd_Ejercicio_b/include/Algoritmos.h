#ifndef ALGORITMOS_H
#define ALGORITMOS_H
#include <NTL/ZZ.h>

using namespace NTL;

class Algoritmos
{
    public:
        Algoritmos();
        ZZ algoritmo1(ZZ,ZZ);
        ZZ algoritmo2(ZZ,ZZ);
        ZZ algoritmo3(ZZ,ZZ);
        ZZ algoritmo3_5(ZZ,ZZ);
        ZZ algoritmo4(ZZ,ZZ);
        ZZ algoritmo5(ZZ,ZZ);
        ZZ algoritmo6(ZZ,ZZ);

        ZZ fun_mod(ZZ,ZZ);
        ZZ fun_abs(ZZ);


    protected:

    private:
};

#endif // ALGORITMOS_H

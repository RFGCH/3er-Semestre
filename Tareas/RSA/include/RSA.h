#ifndef RSA_H
#define RSA_H
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <mat.h>
#include <NTL/ZZ.h>
#include <iostream>

using namespace std;
using namespace NTL;


class RSA
{
    public:

        RSA(ZZ);
        string cifrar(string,ZZ,ZZ);
        string descifrar(string);

        ZZ aleatorio(ZZ,string,ZZ);
        void generarclave(ZZ);
        string cifrar_str(ZZ,ZZ);
        int descifrar_str(string,int);
        ZZ pow_desc(ZZ);
        ZZ tam(ZZ);

        string alfabeto;
        ZZ publica;
        ZZ n;

        mat fun;

    private:

        ZZ privada;
        ZZ p;
        ZZ q;

};

#endif // RSA_H

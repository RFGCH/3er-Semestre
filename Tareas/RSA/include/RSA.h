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

        RSA();
        ZZ cifrar(string,ZZ,ZZ);
        string descifrar(ZZ);

        ZZ aleatorio(ZZ,string,ZZ);
        void generarclave();

        string alfabeto;
        ZZ publica;
        ZZ n;

        mat fun;

    private:
        ZZ privada;

};

#endif // RSA_H

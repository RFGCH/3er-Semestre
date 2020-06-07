#ifndef AFIN_H
#define AFIN_H
#include <string>
#include <stdlib.h>
#include <time.h>
#include <mat.h>

using namespace std;

class Afin
{
    public:
        Afin();
        Afin(int a,int b);
        string cifrado(string);
        string descifrado(string);

        void generarclave();
        int aleatorio();

        int a,b;
        mat func;
        string alfabeto;

    private:
};

#endif // AFIN_H

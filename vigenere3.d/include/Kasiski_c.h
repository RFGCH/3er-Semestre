#ifndef KASISKI_C_H
#define KASISKI_C_H
#include <string>

using namespace std;

class Kasiski_c
{
    public:

        Kasiski_c(string);
        string bloques();
        int longitud();
        void iguales(int,int);
        int fun_mod(int,int);
        int mcd(int,int);

        string alfabeto;
        string mensaje;
        int sub_cadena[10];
        int vuelta;
        int tam_mensaje;
        int length;
        string clave;

    private:
};

#endif // KASISKI_C_H

#ifndef VIGENERE_C_H
#define VIGENERE_C_H
#include <string>

using namespace std;

class Vigenere_c
{
public:

    Vigenere_c();

    string cifrado(string, string);
    string descifrar(string, string);

    string alfabeto_NUM;
    string alfabeto_ASCII;
    string alfabeto_HEX;

private:

    string clave;

};

#endif // VIGENERE_C_H

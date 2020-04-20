#include <iostream>
#include "Vigenere_c.h"

using namespace std;

int main()
{
    Vigenere_c emisor;
    Vigenere_c receptor;

    string mensaje;
    getline(cin,mensaje);

    string mensaje_cifrado = emisor.cifrado(mensaje,"NUM");
    string mensaje_desifrado = receptor.descifrar(mensaje_cifrado,"NUM");
    cout << mensaje_cifrado << endl;
    cout << mensaje_desifrado;
    return 0;
}

#include <iostream>
#include "Cesar.h"

using namespace std;


int main()
{
    Cesar emisor;
    Cesar receptor;

    string mensaje;
    getline(cin,mensaje);

    string mensaje_cifrado = emisor.cifrado(mensaje);
    string mensaje_desifrado = receptor.descifrar(mensaje_cifrado);
    cout << mensaje_cifrado << endl;
    cout << mensaje_desifrado;

    return 0;
}

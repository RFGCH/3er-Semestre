#include <iostream>
#include <Afin.h>

using namespace std;

int main()
{
    Afin a;
    Afin b(a.a,a.b);
    string mensaje = "holasadfijhabvsxuiastxcgawrd";
    string desmensaje = a.cifrado(mensaje);
    cout << desmensaje << endl;
    cout << b.descifrado(desmensaje);
    return 0;
}

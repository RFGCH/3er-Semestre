#include <iostream>
#include <Afin.h>
#include <fstream>

using namespace std;

int main()
{

    ofstream texto("Datos_alg_6.txt");

/*
    Afin a;
    Afin b(a.a,a.b);
    cout << a.a << " " << a.b << endl;
    string mensaje = "Tarea completa 20* 191-10-45131 Ruben Felix GUZMAN CHIROQUE";
    string desmensaje = a.cifrado(mensaje);
    cout << desmensaje << endl;
    cout << b.descifrado(desmensaje);
*/
    int a,b;
    a = 61;
    b = 35;
    Afin an(a,b);
    string desmensaje = an.descifrado("djG3kMddkT,Mdr,d(eVeSe-SzAseHEdoXC6duC6 Ckuo6*CMo>)XDI");
    cout << desmensaje << endl;
    texto << desmensaje;

    return 0;
}

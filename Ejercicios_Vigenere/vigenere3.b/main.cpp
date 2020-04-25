#include <iostream>
#include <locale.h>
#include <windows.h>
#include "Vigenere_c.h"

using namespace std;
int main()
{

    setlocale(LC_ALL, "spanish");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    cout << "ñ";
    Vigenere_c receptor;

    string cadena;
    getline(cin,cadena);

    string aux = receptor.cifrado(cadena,"");
    cout << aux << endl;
    aux = receptor.descifrar(aux,"");
    cout << aux << endl;

    return 0;
}

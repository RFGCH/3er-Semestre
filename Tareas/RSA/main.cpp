#include <iostream>
#include <RSA.h>
#include <mat.h>
#include <fstream>

using namespace std;

int main()
{
    RSA Juan(conv<ZZ>(64));
    string cifrado = Juan.cifrar_Firma_Digital("Hola mundo",Juan.publica,Juan.n);
    string descifrado = Juan.descifrar_Firma_Digital(cifrado,Juan.publica,Juan.n);
    //cout << cifrado <<endl;
    cout << descifrado <<endl;

    return 0;
}

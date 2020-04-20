#include <iostream>
#include <Vigenere_c.h>
using namespace std;

int main()
{
    Vigenere_c a;
    string inicial;
    getline(cin,inicial);
    string codificado = a.cifrado(inicial);
    string decodificado = a.descifrar(codificado);
    cout << codificado << endl;
    cout << decodificado << endl;
    return 0;
}

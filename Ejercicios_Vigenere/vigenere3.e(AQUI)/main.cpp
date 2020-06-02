#include <iostream>
#include <Vigenere_c.h>
using namespace std;

int main()
{

    Vigenere_c f;
    string a;
    getline(cin,a);

    string cifrado_a = f.cifrado(a);
    cout << cifrado_a << endl;
    cout << f.descifrar(cifrado_a);
    return 0;
}

#include <iostream>
#include <RSA.h>
using namespace std;

int main()
{
    RSA a;
    RSA b;
    ZZ cifrado = a.cifrar("g",b.publica,b.n);

    cout << b.descifrar(cifrado);
    return 0;
}

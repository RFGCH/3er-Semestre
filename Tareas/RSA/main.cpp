#include <iostream>
#include <RSA.h>
using namespace std;

int main()
{
    RSA a;
    ZZ aux = a.cifrar("g",a.publica,a.n);

    cout << a.descifrar(aux);
    return 0;
}

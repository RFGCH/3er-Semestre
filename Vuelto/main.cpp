#include <iostream>

using namespace std;

int main()
{
    //Apartir de los 2000 solo se guardaan los primeros 2 digitos

    float x;
    cout << "Ingrese el monto: ";
    cin>>x;
    int a = x/10;
    int b = 0;

    b=a/20;
    a%=20;
    if(b!=0)
    cout << b << " billetes de Doscientos"<< endl;

    b=a/10;
    a%=10;
    if(b!=0)
    cout << b << " billetes de cien"<< endl;

    b=a/5;
    a%=5;
    if(b!=0)
    cout << b << " billetes de cincuenta"<< endl;

    b=a/2;
    a%=2;
    if(b!=0)
    cout << b << " billetes de veinte"<< endl;

    b=a/1;
    a%=1;
    if(b!=0)
    cout << b << " billetes de diez"<< endl;

    cout << "De los " << x << endl;

    return 0;
}

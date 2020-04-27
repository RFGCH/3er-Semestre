#include "Binario.h"
#include <iostream>

using namespace std;
Binario::Binario()
{}

int Binario::mcd_Binario(int a,int b){
    int t,g;
    g=1;
    int con=1;

    if(a<0)a=-a;
    if(b<0)b=-b;

    cout << "\n\Binario 1:\n" << endl;
    cout << "	 g     a     b\n" << endl;
    cout << "\n        ---Parte "<<con++<<"----" << endl;
    cout << "Paso 1  " << g << "   " << a <<"   " << b << "    -"<< endl;
    while(a%2==0&&b%2==0){
        cout << "Paso 2  " << g << "   " << a << "   " << b << "  aumenta g hasta que a%2!=0 && b%2!=0" <<   endl;
        a/=2;
        b/=2;
        g*=2;
    }
    cout << "\n        ---Parte "<<con++<<"----" << endl;
    while(a!=0){

        cout << "Paso 3  " << g << "   " << a << "   " << b << "  si a es par a/=2, si b es par b/=2; " << endl;
        if(a%2==0)a/=2;
        else if(b%2==0)b/=2;
        else {
        cout << "Paso 4  " << g << "   " << a << "   " << b << "  si uno es impar aplica(|a-b|/2,b)" << endl;
            if(a-b<0)t=(b-a)/2;
            else t=(a-b)/2;
            if(a>=b)a=t;
            else b=t;
        }
    }

    return g*b;

}

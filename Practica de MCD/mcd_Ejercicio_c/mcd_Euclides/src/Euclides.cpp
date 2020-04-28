#include "Euclides.h"
#include <iostream>

using namespace std;

Euclides::Euclides()
{}

int Euclides::Euclides_fun(int a,int b){
    int con=1;
    if(a==0)a=b;
    cout << "\n\tEuclides 1:\n" << endl;
    cout << "	 a     b     r\n" << endl;
    cout << "Paso 1  " << a <<"   " << b << "    -"<< endl;
    while(b!=0){
    cout << "\n        ---Vuelta "<<con<<"----" << endl;
        aux=fun_mod(a,b);
        cout << "Paso 2  " << a << "   " << b << "   " << aux << endl;
        a=b;
        b=aux;
        cout << "Paso 3  " << a << "   " << b << "   " << aux <<endl;
    }
    cout << "Paso 4  " << "return " << a <<  endl;
    return a;
}

int Euclides::fun_mod(int a,int b){
    return a-b*floor(a/b+0.5);
}

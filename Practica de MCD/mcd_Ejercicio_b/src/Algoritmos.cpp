#include "Algoritmos.h"
#include <iostream>

using namespace std;
Algoritmos::Algoritmos(int a,int b)
{
    aux = a;
    bux = b;
}

int Algoritmos::algoritmo1(){
    int r;
    int a = aux;
    int b = bux;
    int con=1;
    cout << "\n\tAlgoritmo 1:\n" << endl;
    cout << "	 a     b     r\n" << endl;
    cout << "Paso 1  " << a <<"   " << b << "    -"<< endl;
    while(true){
        cout << "\n        ---Vuelta "<<con<<"----" << endl;
        r=a%b;
        cout << "Paso 2  " << a << "   " << b << "   " << r << endl;
        cout << "Paso 3  " << a << "   " << b << "   " << r << endl;
        if(r==0){
            cout << "True;"<< endl;
            return b;
        }
        cout << "False;" << endl;
        a=b;b=r;
        cout << "Paso 4  " << a << "   " << b << "   " << r << endl;
        con++;
    }
}
int Algoritmos::algoritmo2(){
    int r;
    int a = aux;
    int b = bux;
    int con=1;
    cout << "\n\tAlgoritmo 2:\n" << endl;
    cout << "	 a     b     r\n" << endl;
    cout << "Paso 1  " << a <<"   " << b << "    -"<< endl;
    while(true){
        cout << "\n        ---Vuelta "<<con<<"----" << endl;
        r=a%b;
        cout << "Paso 2  " << a << "   " << b << "   " << r << endl;
        cout << "Paso 3  "<<a<<"   "<<b<<"   "<<r<<"    r="<<r<<";";
        if(r==0){
            cout << "True;"<< endl;
            return b;
        }
        cout << "False;" << endl;
        cout << "Paso 4  " << a << "   " << b << "   " << r <<"    r>="<<b/2<<";";
        if(r>b/2){
            r=b-r;
            cout << "True;"<< endl;
        }
        else cout << "False;" << endl;
        a=b;b=r;
        cout << "Paso 5  " << a << "   " << b << "   " << r << endl;
        con++;
    }
}

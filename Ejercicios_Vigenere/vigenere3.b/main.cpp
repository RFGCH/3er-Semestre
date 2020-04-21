#include <iostream>
#include "Vigenere_c.h"
#include <fstream>

using namespace std;

int main()
{
    Vigenere_c receptor;

    ofstream a;
    a.open("mensaje.txt");
    string mensaje="The MEgraph application used to display this network combines techniques such as topological range searching and motion highlighting to enable interactive exploration of complex network diagrams";
    int aux;
    cin>>aux;
    if(aux==1){
    mensaje = receptor.cifrado(mensaje,"NUM");
    cout << mensaje << endl;
    a<<mensaje;
    }
    else{
    string mensaje = receptor.descifrar(mensaje,"NUM");
    cout << mensaje << endl;
    a<<mensaje;
    }
    return 0;
}

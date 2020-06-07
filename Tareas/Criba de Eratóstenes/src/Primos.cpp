#include "Primos.h"
#include <iostream>
using namespace std;
Primos::Primos()
{
    //Inicializamos una lista del 1 al 100
    lista = new int [100];
    for(int i=1;i<101;i++){
        lista[i]=i;
    }

    int listaux[lista[1]/100]=lista;
    for(int i=lista[1]/100;i>0;i--){

    }

}

void Primos::eliminar(int cont){



}

Primos::~Primos()
{
   delete lista;
}

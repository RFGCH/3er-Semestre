#include "Afin.h"

Afin::Afin(){
    srand(time(NULL));

    alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
    generarclave();

}
Afin::Afin(int a, int b){
    alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
    this -> b=b;
    this -> a=func.inv_mult(a,alfabeto.size());
}

void Afin::generarclave(){

    int siz=alfabeto.size();
    b = (aleatorio()%(siz-1)+1);
    a = (aleatorio()%(siz-1)+2);
    while(func.mcd(a,siz)!=1)
        a = (aleatorio()%(siz-1)+2);

}

string Afin::cifrado(string mensaje){

    int aux, pos;
    int tam = mensaje.size();
    int abc = alfabeto.size();
    for(int i=0;i<tam;i++){
        pos = alfabeto.find(mensaje[i]);
        aux = pos*a+b;
        aux=func.mod(aux,abc);
        mensaje[i]=alfabeto[aux];
    }
    return mensaje;

}
string Afin::descifrado(string mensaje){

    int aux, pos;
    int tam = mensaje.size();
    int abc = alfabeto.size();
    for(int i=0;i<tam;i++){
        pos = alfabeto.find(mensaje[i]);
        aux = a*(pos-b);
        aux=func.mod(aux,abc);
        mensaje[i]=alfabeto[aux];
    }
    return mensaje;

}

int Afin::aleatorio(){
    return rand();
}

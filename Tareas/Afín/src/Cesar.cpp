#include "Cesar.h"

Cesar::Cesar()
{
   alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
}

string Cesar::cifrado(string mensaje, int clave){


    int aux, pos;
    int tam = mensaje.size();
    int abc = alfabeto.size();
    for(int i=0;i<tam;i++){
        pos = alfabeto.find(mensaje[i]);
        aux = pos+clave;
        aux=mod(aux,abc);
        mensaje[i]=alfabeto[aux];
    }
    return mensaje;
}
string Cesar::descifrar(string mensaje,int clave){

    int aux, pos;
    int tam = mensaje.size();
    int abc = alfabeto.size();
    for(int i=0;i<tam;i++){
        pos = alfabeto.find(mensaje[i]);
        aux = pos-clave;
        aux=mod(aux,abc);
        mensaje[i]=alfabeto[aux];
    }
    return mensaje;
}
int Cesar::mod(int a,int b){
    int r = a-b*(a/b);
    if(r<0)return r+b;
    return r;
}

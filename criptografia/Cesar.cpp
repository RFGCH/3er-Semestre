#include "Cesar.h"

Cesar::Cesar()
{
   alfabeto="abcdefghijklmnopqrstuvxyz";
   clave=26;
}

string Cesar::cifrado(string mensaje){

    int aux, pos;
    for(int i=0;i<mensaje.size();i++){
        pos = alfabeto.find(mensaje[i]);
        if(pos!=string::npos){
        aux = (pos+clave)%alfabeto.size();
        mensaje[i]=alfabeto[aux];
        }
    }
    return mensaje;
}
string Cesar::descifrar(string mensaje){

    int aux, pos;
    for(int i=0;i<mensaje.size();i++){
        pos = alfabeto.find(mensaje[i]);
        if(pos!=string::npos){
        aux = pos-clave;
        while(aux<0)aux+=alfabeto.size();
        mensaje[i]=alfabeto[aux];
        }
    }
    return mensaje;

}

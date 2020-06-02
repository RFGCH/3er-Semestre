#include "Vigenere_c.h"
#include <iostream>
Vigenere_c::Vigenere_c()
{
    alfabeto =  "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
    clave = "HDEBRU";
}
string Vigenere_c::cifrado(string mensaje){

    aqui(mensaje);

    int aux, pos1, pos2;
    int iterador = 0;
    int tam_mens = mensaje.size();
    int tam_abc = alfabeto.size();
    int tam_codigo = clave.size();



    for(int i=0;i<tam_mens;i++){

        if(iterador>=tam_codigo)iterador=0;
        pos1 = alfabeto.find(clave[iterador]);
        iterador++;
        pos2 = alfabeto.find(mensaje[i]) + pos1;
        while(pos2>=tam_abc)

            pos2-=tam_abc;

        mensaje[i] = alfabeto[pos2];
    }

    return mensaje;

}

string Vigenere_c::aqui(string mensaje){

    int tam_mens = mensaje.size();

    for(int i=10;i<tam_mens;i+=14){
            mensaje.insert(i,"AQUI");
            tam_mens+=4;
        }

    for(int i=4-tam_mens%4;i>0;i--)mensaje+="W";

    return mensaje;

}
string Vigenere_c::desaqui(string mensaje){

    int tam_mens = mensaje.size();

    while(mensaje[tam_mens-1]=='W'){
        mensaje.replace(tam_mens-1,1,"");
        tam_mens--;
    }

    for(int i=10;i<tam_mens;i+=10){
            mensaje.erase(i,4);
            tam_mens=mensaje.size();
    }
    return mensaje;
}

string Vigenere_c::descifrar(string mensaje){



    int aux, pos1,pos2;
    int iterador = 0;
    int tam_mens = mensaje.size();
    int tam_abc = alfabeto.size();
    int tam_codigo = clave.size();

    for(int i=0;i<tam_mens;i++){

        if(iterador>=tam_codigo)iterador=0;
        pos1 = alfabeto.find(clave[iterador]);
        iterador++;
        pos2 = alfabeto.find(mensaje[i]) -pos1;

        while(pos2<0)

            pos2+=tam_abc;

        mensaje[i] = alfabeto[pos2];
    }

    mensaje = desaqui(mensaje);

    return mensaje;
}

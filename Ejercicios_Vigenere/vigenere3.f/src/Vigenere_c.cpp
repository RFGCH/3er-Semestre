#include "Vigenere_c.h"
#include <iostream>
Vigenere_c::Vigenere_c()
{
    alfabeto =  "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
    clave = "LHC";
}
string Vigenere_c::cifrado(string mensaje){

    int aux, pos1, pos2;
    int iterador = 0;
    int tam_mens = mensaje.size();
    int tam_abc = alfabeto.size();
    int tam_codigo = clave.size()-1;
    string clave_aux = "AUTOCLAVE";
    int iterador_aux = 0;
    int tam_codigo_aux = clave_aux.size();

    for(int i=0;i<tam_mens;i++){

        if(iterador_aux>tam_codigo_aux)iterador_aux=0;
        if(iterador>tam_codigo){
            pos1= alfabeto.find(clave[iterador_aux]);
            iterador_aux++;
        }
        else {
            pos1 = alfabeto.find(clave[iterador]);
            iterador++;
        }

        pos2 = alfabeto.find(mensaje[i]) + pos1;
        while(pos2>=tam_abc)

            pos2-=tam_abc;

        mensaje[i] = alfabeto[pos2];
    }
    return mensaje;

}
string Vigenere_c::descifrar(string mensaje){

    int aux, pos1,pos2;
    int iterador = 0;
    int tam_mens = mensaje.size();
    int tam_abc = alfabeto.size();
    int tam_codigo = clave.size()-1;
    string clave_aux = "AUTOCLAVE";
    int iterador_aux = 0;
    int tam_codigo_aux = clave_aux.size();

    for(int i=0;i<tam_mens;i++){

        if(iterador_aux>tam_codigo_aux)iterador_aux=0;
        if(iterador>tam_codigo){
            pos1= alfabeto.find(clave[iterador_aux]);
            iterador_aux++;
        }
        else {
            pos1 = alfabeto.find(clave[iterador]);
            iterador++;
        }

        pos2 = alfabeto.find(mensaje[i])-pos1;

        while(pos2<0)

            pos2+=tam_abc;

        mensaje[i] = alfabeto[pos2];
    }

    return mensaje;
}

#include "Vigenere_c.h"
#include <iostream>
Vigenere_c::Vigenere_c()
{
    alfabeto =  "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
    clave = "PERO CASI";
}
string Vigenere_c::cifrado(string mensaje){

    int aux, pos1,pos2;
    int tam_mens = mensaje.size();
    int tam_abc = alfabeto.size();
    int tam_codigo = clave.size();

    for(int i=0;i<tam_mens;i++){

        if(i<tam_codigo)
            pos1 = alfabeto.find(clave[i]);

        else
            pos1 = alfabeto.find(clave[i-tam_codigo]);
        cout << pos1 << "  " ;
        pos2 = alfabeto.find(mensaje[i]) + pos1;

        if(pos2>tam_abc)

            pos2%=tam_abc;
        cout << pos2 << endl;
        mensaje[i] = alfabeto[pos2];
    }

    return mensaje;

}
string Vigenere_c::descifrar(string mensaje){

    int aux, pos1,pos2;
    int tam_mens = mensaje.size();
    int tam_abc = alfabeto.size();
    int tam_codigo = clave.size();

    for(int i=0;i<tam_mens;i++){

        if(i<tam_codigo)
            pos1 = alfabeto.find(clave[i]);

        else
            pos1 = alfabeto.find(clave[i-tam_codigo]);
        cout << pos1 << "  " ;
        pos2 = alfabeto.find(mensaje[i]) - pos1;

        if(pos2<0)
            pos2%=tam_abc;

        cout << pos2 << endl;
        mensaje[i] = alfabeto[pos2];
    }

    return mensaje;
}

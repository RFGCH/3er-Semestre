#include "Kasiski_c.h"
#include <iostream>

Kasiski_c::Kasiski_c(string mensaje)
{
    alfabeto =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ,. ";
    this -> mensaje = mensaje;
    vuelta = 0;
    tam_mensaje = mensaje.size();
    length = longitud();
    clave = bloques();

}
string Kasiski_c::bloques(){

    string bloques[length];
    for(int i=0;i<length;i++){
        for(int j=i;j<tam_mensaje;j+=length){
            bloques[i]+=mensaje[j];
        }
    }


    int a, b, pos;
    string string_1="";
    string final_1="";

    for(int i=0;i<length;i++){
        b=0;
        int tam = bloques[i].size();
        cout << "Cadena: " << bloques[i]<< ". "  <<  endl;
        for(int j=0;j<tam;j++){//Encontrar la ocuerrencia de la palabra en el bloque a fuerza bruta
            a=0;
            char aux_char=bloques[i][j];
            pos=bloques[i].find(aux_char);
            for(;pos!=string::npos;a++){
                pos=bloques[i].find(aux_char,pos+1);
            }

            cout << "Letra: " << bloques [i][j] << "  Veces Repetida: " << a << endl;
            if(a>b){
                string_1=bloques[i][j];
                b=a;
            }

        }
        final_1+=string_1;
    }
    cout << "Longitud: " << length  << endl;
    cout << "Clave: " << final_1 << endl;

    return final_1;
}

int Kasiski_c::longitud(){

    iguales(3,0);
    if(vuelta!=10)iguales(4,0);

    int aux,aux_1,lengh;
    for(int i=0;i<vuelta-2;i++){
        aux=mcd(sub_cadena[i],sub_cadena[i+1]);
        aux_1=mcd(sub_cadena[i+1],sub_cadena[i+2]);
        if(aux_1>aux)lengh=aux;
    }
    return lengh;
}
void Kasiski_c::iguales(int Tam,int inicio){

    if(inicio>tam_mensaje-Tam||vuelta==10)return;

    string aux;
    for(int i=inicio;i<Tam+inicio;i++)
        aux += mensaje[i];
    int pos = mensaje.find(aux,inicio);
    int aux_2 = mensaje.find(aux,pos+Tam);
    if(aux_2!=string::npos){
        sub_cadena[vuelta]=aux_2-pos;
        vuelta++;
    }

    iguales(Tam,inicio+Tam);
}
int Kasiski_c::fun_mod(int a,int b){
    int aux=b;
    for(;b<=a;b+=aux){}
    b-=aux;
    return a-b;
}
int Kasiski_c::mcd(int a, int b){
    if(b==0)return a;
    int r = fun_mod(a,b);
    mcd(b,r);
}


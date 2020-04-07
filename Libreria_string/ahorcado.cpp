#include "ahorcado.h"
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

ahorcado::ahorcado()
{
    set_values();
}
void ahorcado::set_values(){

    palito="";
    intentos=0;
    palabra_clave = getpalabra();
    run = 1;

    string aux1(palabra_clave.size(),'x');
    palabra = aux1;

    init();
}
void ahorcado::init(){
    if(run){
        print();
        proceso_de_palabra();
        comprobar();
        init();
    }
}
void ahorcado::print(){
    system("cls");
    cout <<"\n\t\t***Bienvenido a el ahorcado***\n"<< palito << endl;
    cout <<"     Adivinar la siguiente palabra: "<< palabra<< endl;
    cout <<"     Ingrese su palabra: ";
}
void ahorcado::proceso_de_palabra(){

    string aux;
    getline(cin,aux);

    if(aux.size()-1)
        palabra_str(aux);
    else
        letra_str(aux);

}
void ahorcado::letra_str(string intento){

    int pos = palabra_clave.find(intento);
    if(pos==string::npos){
        intentos++;
        palito_str();
    }

    while(pos != string::npos){
        palabra.replace(pos,1,intento);
        pos=palabra_clave.find(intento,++pos);
    }
}
void ahorcado::palabra_str(string intento){

    if(intento==palabra_clave)
        fin_del_juego();
    else {
        intentos++;
        palito_str();
    }

}
void ahorcado::fin_del_juego(){
    string aux;
    system("cls");
    cout << "\n\t\tGracias por jugar a el ahoracado\t\n\n";
    if(intentos==7)cout << palito;
    cout << "\t  La palabra es: " << palabra_clave << endl;
    cout << "\n\t  Quiere jugar de nuevo? si/no: ";
    getline(cin,aux);
    if (aux=="si"){
        run=1;
        set_values();
    }
    else run=0;
}
void ahorcado::comprobar(){

    if(intentos==7||palabra==palabra_clave)
        fin_del_juego();

}
void ahorcado::palito_str(){
    string aux[]={"\n\to\n","       /","|","\\\n","\t|\n","       /"," \\"};
    palito+=aux[intentos-1];
}
ahorcado::~ahorcado(){
}

string ahorcado::getpalabra(){

    int aux = numero_aleatorio();
    string aux1;

    ifstream entrada("ahorcado.txt");
    while(aux--)
        getline(entrada,aux1);
    entrada.close();

        return aux1;

}
int ahorcado::numero_aleatorio(){

    srand(time(NULL));
        return 1+rand()%10;

}

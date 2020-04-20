#include <iostream>
#include <Vigenere_c.h>
using namespace std;
int fun_mod(int b,int a){
    int aux=a;
    for(;a<b;a+=aux){}
    return a-b;
}
string Kasiski(string cifrado){
    int tam=3;
    int encontrados=0;
    int posiciones[10];
    string aux;
    int ini=0;
    int fin=2;
    int length=cifrado.size();
    while(encontrados<5){
        int busqueda=0;
        while(busqueda<length&&encontrados<5){
            ini++;fin++;
            for(int i=ini;i<fin;i++)
                aux+=cifrado[i];
            int pos=cifrado.find(aux);
            int pos2=cifrado.find(aux,pos+1);
            cout << pos << " " << pos2 << endl;
            if(pos!=string::npos){
                pos2-=pos;
                posiciones[encontrados]=pos2;
                encontrados++;
            }
            busqueda++;
        }
        fin++;
    }
    return "aun no lo completo...";
}
int main()
{
    cout << fun_mod(6,6);
    Vigenere_c a;
    string aux;
    string texto_cifrado;
    cout << "Ingresar el texto: ";
    getline(cin,aux);
    texto_cifrado=a.cifrado(aux);
    Kasiski(texto_cifrado);
    return 0;
}
